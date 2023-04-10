# Account Management

## structure

- ### .h file

  - account.h         //账户类
  - date.h               //日期类
  - accumulator.h //将某个数值按日累加

- ### .cpp file
  
  - account.cpp      //账户类的实现
  - date.cpp            //日期类的实现
  - main.cpp           //主程序

## usage

### (a)add account 

`a type` type of the account: (s)savingsAccount/(c)creditAccount

e.g.,

`a s`

### (d)deposit 

`d index amount description` 

e.g.,

`d 0 5000 salary` 

### (w)withdraw

`w index amount description` 

 e.g.,

`w 2 2000 buy a cell`

### (s)show 

### (c)change day 

`c "the day of the same month`" 

e.g.,

`c 5`

### (n)next month 

### (q)query 

`q start_date end_date ` date: year-month-day

e.g.,

`q 2022-12-5 2023-1-5`

### (e)exit