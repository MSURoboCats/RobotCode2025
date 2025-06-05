# MOTOR_COMMANDS_GLOSSARY.MD

## MOTOR GOALS -- managed by motor conductor
1.  cont     = continue last goal
2.  kill     = Stop All Motors
3.  halt     = kill all velocity and then stop the motors
4.  f_sl    = Forward Slow
5.  r_sl    = Reverse Slow
6.  f_me    = Forward Medium
7.  r_me    = Reverse Medium
8.  f_fa    = Forward Fast
9.  r_fa    = Reverse Fast
10. u_sl    = Up Slow
11. d_sl    = Down Slow
12. u_me    = Up Medium
13. d_me    = Down Medium
14. u_fa    = Up Fast
15. d_fa    = Down Fast 

## MOTOR COMMANDS -- managed by motor controller

   -1 = Continue Previous Command / Ignore
    0 = Stop Motor
    1 = Forward Slow
    2 = Reverse Slow
    3 = Forward Medium
    4 = Reverse Medium
    5 = Forward Fast
    6 = Reverse Fast 

## I2C CHANNELS

0 = PWM 1 (Front right if looking out from camera)
1 = PWM 2 (Mid right if looking out from camera)
2 = PWM 3 (Back right if looking out from camera)
3 = PWM 4 (Back left)
4 = PWM 5 (Mid Left)
5 = PWM 6 (Front left)
