import tkinter as tk
from tkinter import filedialog

window = tk.Tk()
window.title("Encrypted Keystroke Logger")

e1 = tk.Entry(window)
e1.grid(row=3, column=2)

start_button = tk.Button(window, text="Start Logging", command=start_logging)
start_button.grid(row=4, column=2)

stop_button = tk.Button(window, text="Stop Logging", command=stop_logging)
stop_button.grid(row=5, column=2)

search_button = tk.Button(window, text="Search Logs", command=search_logs)
search_button.grid(row=6, column=2)

quit_button = tk.Button(window, text="Quit", command=quit_logger)
quit_button.grid(row=7, column=2)

def start_logging():
    keylogger.start_logging()

def stop_logging():
    keylogger.stop_logging()

def search_logs():
    file_path = filedialog.askopenfilename()
    encryption.decrypt_log(file_path)

def quit_logger():
    window.destroy()

window.mainloop()