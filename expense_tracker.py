
"""
Expense Tracker GUI
Part 1 starter version.
Features:
- Add Expense
- View in table
- Save/load JSON
- Delete selected
- Calculate total
"""

import json
import os
import tkinter as tk
from tkinter import ttk, messagebox

FILE_NAME="expenses.json"

def load_data():
    if os.path.exists(FILE_NAME):
        try:
            with open(FILE_NAME,"r") as f:
                return json.load(f)
        except:
            return []
    return []

expenses=load_data()

def save_data():
    with open(FILE_NAME,"w") as f:
        json.dump(expenses,f,indent=4)

def refresh():
    for row in tree.get_children():
        tree.delete(row)
    for i,e in enumerate(expenses):
        tree.insert("",tk.END,iid=i,values=(
            e["date"],e["amount"],e["category"],e["description"]
        ))

def clear():
    date_var.set("")
    amount_var.set("")
    category_var.set("")
    desc_var.set("")

def add():
    if not date_var.get() or not amount_var.get() or not category_var.get():
        messagebox.showerror("Error","Please complete all required fields.")
        return
    try:
        amount=float(amount_var.get())
    except:
        messagebox.showerror("Error","Amount must be numeric.")
        return

    expenses.append({
        "date":date_var.get(),
        "amount":amount,
        "category":category_var.get(),
        "description":desc_var.get()
    })
    save_data()
    refresh()
    clear()
    messagebox.showinfo("Success","Expense added.")

def delete():
    sel=tree.selection()
    if not sel:
        messagebox.showwarning("Warning","Select an expense.")
        return
    idx=int(sel[0])
    expenses.pop(idx)
    save_data()
    refresh()

def total():
    t=sum(e["amount"] for e in expenses)
    messagebox.showinfo("Total",f"Total Expenses: ${t:.2f}")

root=tk.Tk()
root.title("Expense Tracker")
root.geometry("900x600")

tk.Label(root,text="Expense Tracker",font=("Arial",22,"bold")).pack(pady=10)

frm=tk.Frame(root)
frm.pack()

date_var=tk.StringVar()
amount_var=tk.StringVar()
category_var=tk.StringVar()
desc_var=tk.StringVar()

labels=["Date","Amount","Category","Description"]
for r,l in enumerate(labels):
    tk.Label(frm,text=l).grid(row=r,column=0,sticky="w",padx=10,pady=5)

tk.Entry(frm,textvariable=date_var,width=30).grid(row=0,column=1)

tk.Entry(frm,textvariable=amount_var,width=30).grid(row=1,column=1)

ttk.Combobox(frm,textvariable=category_var,
values=["Food","Transport","Shopping","Bills","Entertainment","Other"],
width=27).grid(row=2,column=1)

tk.Entry(frm,textvariable=desc_var,width=30).grid(row=3,column=1)

b=tk.Frame(root)
b.pack(pady=10)

tk.Button(b,text="Add Expense",command=add,width=15).grid(row=0,column=0,padx=5)
tk.Button(b,text="Delete",command=delete,width=15).grid(row=0,column=1,padx=5)
tk.Button(b,text="Calculate Total",command=total,width=15).grid(row=0,column=2,padx=5)
tk.Button(b,text="Clear",command=clear,width=15).grid(row=0,column=3,padx=5)

cols=("Date","Amount","Category","Description")
tree=ttk.Treeview(root,columns=cols,show="headings",height=15)
for c in cols:
    tree.heading(c,text=c)
    tree.column(c,width=180)
tree.pack(fill="both",expand=True,padx=10,pady=10)

refresh()
root.mainloop()
