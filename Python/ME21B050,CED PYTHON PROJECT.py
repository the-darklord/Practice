# Start of Program
import random

# Number of Iterations is Square of INTERVAL
INTERVAL= int(input("Enter a Interval : "))
t=INTERVAL**2

# Initialising Number of Square Points and Circle Points to '0'
circle_points= 0
square_points= 0

# Declaring a Set with Name pi to store value at each iteration
pi={}

for i in range(t):
    # Assuming a Unit Circle so that the Vertices of Square are (-1,1) , (1,1) , (-1,-1) , (1,-1) and Centre of Cirlce is (0,0) or Origin
    # So that every point we are taking will be on or inside the Square
	rand_x= random.uniform(-1, 1)
	rand_y= random.uniform(-1, 1)

    # As it is Unit Circle if a distance of point is less than or equal to 1 , then the point is inside circle and we increment the circle_points
    # If the distance is greater than 1 , then it's outside circle
    # Whatever the distance is the point is either on or inside the Square , so we increment the square_points
	origin_dist= rand_x**2 + rand_y**2

	if origin_dist<= 1:
		circle_points+= 1

	square_points+= 1
 
    # Let side of Square be s and radius of Circle be r and from diagram we can conclude that s=2r
    # From the Monte Carlo Algorithm we get Area of Circle/Area of Square = cirle_points/square_points
    # (pi*r*r)/(s*s)=(pi*r*r)/(4*r*r)=pi/4
    # So pi = 4*circle_points/square_points
    # We store every value of pi after each iteration in the set pi
	pi[i] = 4* circle_points/ square_points

# Printing the final Value of pi

print("The Value of Pi after Final Iteration is : " + str(pi[t-1]))

# End of Program