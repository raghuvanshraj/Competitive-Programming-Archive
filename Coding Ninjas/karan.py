t = int(input())
n = int(input())

in_time_str = input().split(':')
in_time_list = list(map(int, in_time_str))
in_time = in_time_list[0] * 60 + in_time_list[1]

wake_up_str = input().split(':')
wake_up_list = list(map(int, wake_up_str))
wake_up = wake_up_list[0] * 60 + wake_up_list[1]

store_open_str = input().split(':')
store_open_list = list(map(int, store_open_str))
store_open = store_open_list[0] * 60 + store_open_list[1]

print(in_time)
print(wake_up)
print(store_open)
