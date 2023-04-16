// @ts-nocheck
/**
 * (c) Meta Platforms, Inc. and its affiliates. Confidential and proprietary.
 */
 const S = require('Scene');
 const P = require('Patches');
 const R = require('Reactive');
 const A = require('Animation');
 const T = require('Time');
 const TX = require('Textures');

// Constants for the default visual and interaction style.
 const TARGET_ENVELOPE_SCALE = 1.1;
 const ICON_PLANE_DISTANCE = 0.1;
 const DEFAULT_PLANE_SIZE = 0.1;
 const PLANE_TO_TARGET_TRACKER_RATIO = 3;
 const ICON_FADE_DURATION = 500;
 const ICON_START_DELAY = 0;
 const ICON_INSTRUCTONS_DURATION = 4000;
 const RETICLE_TRANSITION_DURATION = 500;
 const RETICLE_FADE_DURATION = 500;
 const FIT_SCALE = 0.55;

 class TargetTracker {
   constructor(){
     this.reticleTransitionTimeout = null;
     Promise.all([
       S.root.findFirst('Camera'),
       S.root.findFirst('targetTracker0'),
       S.root.findFirst('targetEnvelope'),
       S.root.findFirst('screenFit'),
       S.root.findFirst('icon'),
       S.root.findFirst('reticle'),
       TX.findFirst('replaceMe'),
     ]).then(p=>{
       this.camera = p[0];
       this.targetTracker = p[1];
       this.targetEnvelope = p[2];
       this.screenFit = p[3];
       this.icon = p[4];
       this.reticle = p[5];
       this.targetTexture = p[6];
       this.initAfterPromiseResolved();
     }).catch(e=>{
       D.log('Promise Error: '+e.stack);
     });
   }

   // This method is called after all scene objects are found
   initAfterPromiseResolved(){
     this.aspectRatio = this.targetTexture.width.div(this.targetTexture.height);
     this.setupReticleFade();
     this.setupReticleTransition();
     this.setupTargetEnvelope();
     this.setupScreenFit();
     this.setupReticle();
     this.setupIconFade();
     this.outputToPatch();
   }

   // Setup a square plane to envelop the target image in world space. This serves as an anchor for the reticle. When target is found, the reticle transitions to targetEnvelope
   setupTargetEnvelope(){
     let worldTransform = this.targetTracker.worldTransform;
     this.targetEnvelope.transform.position = worldTransform.position;
     this.targetEnvelope.transform.rotationX = worldTransform.rotationX;
     this.targetEnvelope.transform.rotationY = worldTransform.rotationY;
     this.targetEnvelope.transform.rotationZ = worldTransform.rotationZ;
     this.targetEnvelope.transform.scale = worldTransform.scale
       .mul(R.val(PLANE_TO_TARGET_TRACKER_RATIO))
       .div(this.aspectRatio.gt(1).ifThenElse(R.val(1), this.aspectRatio))
       .mul(TARGET_ENVELOPE_SCALE);
     this.targetInView = this.isTargetInView(
       this.targetEnvelope.transform.position,
       this.targetEnvelope.transform.scaleX.mul(DEFAULT_PLANE_SIZE));
   }

   // Setup a square plane that fits in the center of the screen. This serves as an anchor for the reticle. When tracking is not initialized, the reticle rest around the on-screen target image.
   setupScreenFit(){
     let iconScale = R.val(ICON_PLANE_DISTANCE).div(this.camera.focalPlane.distance);
     let fitSize = this.camera.focalPlane.width.gt(this.camera.focalPlane.height).ifThenElse(
       this.camera.focalPlane.height, this.camera.focalPlane.width);
     this.screenFit.transform.scaleX = iconScale
       .mul(fitSize).div(DEFAULT_PLANE_SIZE).mul(FIT_SCALE);
     this.screenFit.transform.scaleY = iconScale
       .mul(fitSize).div(DEFAULT_PLANE_SIZE).mul(FIT_SCALE);
     this.screenFit.transform.z = R.val(-ICON_PLANE_DISTANCE);
   }

   // Setup the reticle to interpolate between targetEnvelope and screenFit.
   setupReticle(){
     this.reticle.transform = R.mix(
       this.screenFit.transform.toSignal(), this.targetEnvelope.transform.toSignal(),
       this.trackingProgress);
   }

   // Setup the animation driver for reticle transition.
   setupReticleTransition(){
     this.reticleTransitionDriver = A.timeDriver({durationMilliseconds: 1000});
     let animationSampler = A.samplers.easeInOutCubic(0, 1);
     this.trackingProgress = A.animate(this.reticleTransitionDriver, animationSampler);
     this.targetTracker.confidence.monitor({fireOnInitialValue: true}).subscribe(v=>{
       if (this.reticleTransitionTimeout != null) {
         T.clearTimeout(this.reticleTransitionTimeout);
       }
       if (v.newValue != 'NOT_TRACKING') {
         this.reticleTransitionDriver.reset();
         this.reticleTransitionDriver.start();
         this.reticleTransitionTimeout = T.setTimeout(t=>{
           this.fadeReticle();
         }, RETICLE_TRANSITION_DURATION + RETICLE_FADE_DURATION);
       } else {
         this.reticleTransitionDriver.reverse();
         this.showReticle();
       }
     });
   }

   // Setup the animation driver for reticle showing and fading.
   setupReticleFade(){
     this.reticleFadeDriver = A.timeDriver({durationMilliseconds: 1000});
     let animationSampler = A.samplers.easeInOutCubic(1, 0);
     P.inputs.setScalar('reticleFade', A.animate(this.reticleFadeDriver, animationSampler));
     P.inputs.setBoolean('showReticle', true);
   }

   fadeReticle(){
     this.reticleFadeDriver.reset();
     this.reticleFadeDriver.start();
     P.inputs.setBoolean('showReticle', false);
   }

   showReticle(){
     this.reticleFadeDriver.reverse();
     P.inputs.setBoolean('showReticle', true);
   }

   // Setup icon fade animation driver. The on-screen image icon should fade in and out with the instructions.
   setupIconFade(){
     this.iconFadeDriver = A.timeDriver({durationMilliseconds: ICON_FADE_DURATION});
     let animationSampler = A.samplers.easeInOutCubic(0, 1);
     this.iconVisible = true;
     T.setTimeout(t=>{
       this.showIcon();
     },ICON_START_DELAY);
     T.setInterval(() => {
      if (this.iconVisible){
        this.fadeIcon();
      } else {
        this.showIcon();
      }
     }, ICON_INSTRUCTONS_DURATION);
     P.inputs.setScalar('iconFade', A.animate(this.iconFadeDriver, animationSampler));
     P.inputs.setBoolean('showIcon', this.iconVisible);
   }

   fadeIcon(){
     this.iconFadeDriver.reverse();
     this.iconVisible = false;
     P.inputs.setBoolean('showIcon', this.iconVisible);
   }

   showIcon(){
     this.iconFadeDriver.reset();
     this.iconFadeDriver.start();
     this.iconVisible = true;
     P.inputs.setBoolean('showIcon', this.iconVisible);
   }

   // Helper method to project a position in camera space to focal plane space.
   projectToFocalPlane(positionInCameraSpace){
     let focalDistanceOverZ = this.camera.focalPlane.distance.div(positionInCameraSpace.z.abs());
     return R.point(
       positionInCameraSpace.x.mul(focalDistanceOverZ),
       positionInCameraSpace.y.mul(focalDistanceOverZ),
       this.camera.focalPlane.distance);
   }

   // Helper method to project an estimated size to focal plane space.
   projectSizeOnFocalPlane(positionInCameraSpace, sizeInCameraSpace){
     let focalDistanceOverZ = this.camera.focalPlane.distance.div(positionInCameraSpace.z.abs());
     return sizeInCameraSpace.mul(focalDistanceOverZ);
   }

   // Helper method to estimate if the target is in camera's view
   isTargetInView(positionInCameraSpace, sizeInCameraSize){
     let position = this.projectToFocalPlane(positionInCameraSpace);
     let size = this.projectSizeOnFocalPlane(positionInCameraSpace, sizeInCameraSize);
     let xEdge = this.camera.focalPlane.width.add(size).div(2);
     let yEdge = this.camera.focalPlane.height.add(size).div(2);
     let isInside = (position.x.lt(xEdge)).and(position.x.gt(xEdge.neg()))
       .and(position.y.lt(yEdge).and(position.y.gt(yEdge.neg())))
       .and(positionInCameraSpace.z.lt(0));
     return isInside;
   }

   // Helper method to determine if the script is running in editor. This is based on the behavior that target tracker and camera is in the same world space position while running in editor.
   isInEditor(){
     let position = this.targetTracker.worldTransform.position;
     let isAtDefaultX = position.x.eq(R.val(0));
     let isAtDefaultY = position.y.eq(R.val(0));
     let isAtDefaultZ = position.z.eq(R.val(0));
     let isAtDefaultPosition = isAtDefaultX.and(isAtDefaultY).and(isAtDefaultZ);
     return isAtDefaultPosition;
   }

   // Output signals for visual and interaction logic done by Patches
   outputToPatch(){
     P.inputs.setScalar('aspectRatio', this.aspectRatio);
     P.inputs.setBoolean('isInEditor', this.isInEditor());
   }
 }

 const instance = new TargetTracker();
 export default instance;
