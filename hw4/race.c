import threading
import time

# 账户余额
balance = 0

# 提款函数
def withdraw(amount):
    global balance
    for _ in range(10000):  # 密集提款操作
        balance -= amount

# 存款函数
def deposit(amount):
    global balance
    for _ in range(10000):  # 密集存款操作
        balance += amount

# 创建线程
threads = []
for _ in range(5):
    t1 = threading.Thread(target=withdraw, args=(1,))
    t2 = threading.Thread(target=deposit, args=(1,))
    threads.append(t1)
    threads.append(t2)

# 启动线程
for t in threads:
    t.start()

# 等待所有线程完成
for t in threads:
    t.join()

print(f"最终余额: {balance}")
#chatgpt輔助
