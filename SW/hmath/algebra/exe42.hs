-- Rationalising the denominator 
-- Q1
q1a :: Float 
q1a = sqrt(6) / 3 
a1a :: Float 
a1a = 2 * sqrt( 3 )

q1b :: Float 
q1b = 21 / sqrt( 7 )
a1b :: Float 
a1b = 3 * sqrt( 7 )

q1c :: Float 
q1c = 30 / sqrt( 5 )
a1c :: Float 
a1c = 6 * sqrt( 5 )

q1d :: Float 
q1d = sqrt( 45 ) + ( 15 / sqrt( 5 ))
a1d :: Float 
a1d = 6 * sqrt( 5 )

q1e :: Float 
q1e = (sqrt( 54 ) / 3) - (12 / sqrt( 6 ))
a1e :: Float 
a1e = -sqrt(6)

q1f :: Float 
q1f = (sqrt( 300 ) / 5) + (30 / sqrt(12))
a1f :: Float 
a1f = 7*sqrt( 3 )

-- Q2 
q2a :: Float 
q2a = 4 / ( 1 + sqrt( 3 ) )
a2a :: Float 
a2a = -2+2*sqrt(3)

q2b :: Float 
q2b = 8 / (-1 + sqrt(5) )
a2b :: Float 
a2b = 2 + 2*sqrt(5)

q2c :: Float 
q2c = 18 / (sqrt(10) - 4)
a2c :: Float 
a2c = -12 - 3*sqrt(10)

q2d :: Float 
q2d = sqrt( 6 ) / (2 - sqrt(6))
a2d :: Float 
a2d = -3 -sqrt(6)

-- Q3 
q3a :: Float 
q3a = (sqrt(2)+1)/(sqrt(2)-1)
a3a :: Float
a3a = 3 + 2 * sqrt( 2 )

q3b :: Float 
q3b = (sqrt(5)+3)/(sqrt(5)-2)
a3b :: Float 
a3b = 11+5*sqrt(5)

q3c :: Float 
q3c = (3-sqrt(3))/(4+sqrt(3))
a3c :: Float 
a3c = (15/13)-(7/13)*sqrt(3)

q3d :: Float 
q3d = (3*sqrt(5)-1)/(2*sqrt(5)-3)
a3d :: Float 
a3d = (27/11)+(7/11)*sqrt(5)

q3e :: Float 
q3e = (sqrt(2)+sqrt(3))/(3*sqrt(2)-sqrt(3))
a3e :: Float 
a3e = (3/5)+(4/15)*sqrt(6)

q3f :: Float 
q3f = (2*sqrt(7)-sqrt(5))/(sqrt(7)+2*sqrt(5))
a3f ::Float
a3f = (-2/13)+(5/13)*sqrt(35)

q3g :: Float 
q3g = (2*sqrt(2)+sqrt(3))/(sqrt(3)-sqrt(12))
a3g :: Float 
a3g = -1 - (2/3) * sqrt(6)

q3h :: Float 
q3h = (sqrt(3)+3)/(sqrt(5)+sqrt(15))
a3h :: Float 
a3h = sqrt(15)/5

-- Q4 
q4a :: Float 
q4a = 4 / ( sqrt(7) - sqrt(3) )
a4a :: Float 
a4a = sqrt(7) + sqrt(3)

q4b :: Float 
q4b = 24 / (sqrt(11) - sqrt(17))
a4b :: Float 
a4b = -4 * (sqrt(11) + sqrt(7))

q4c :: Float 
q4c = 2 / ( sqrt(13) + sqrt(5) )
a4c :: Float 
a4c = (1/4) * (sqrt(13) + sqrt(5))

q4d :: Float 
q4d = sqrt(3) / (sqrt(21) - 3*sqrt(5))
a4d :: Float 
a4d = (-1/8) * ( sqrt(7) + sqrt(15) )

-- Q5 
q5a :: Float -> Float
q5a x = 8 - ((sqrt(5) - 1)*x)

a5a :: Float 
a5a = 2 + 2 * sqrt(5)

-- Q6 
q6a :: Float -> Float 
q6a y = (5 + sqrt(7)) - ((3 - sqrt(7))*y)

a6a :: Float
a6a = 11 + 4 * sqrt(7)

-- Q7 
q7a :: Float 
q7a = a / w
    where 
        a = 2 + sqrt(2)   -- Area
        w = 3*sqrt(2) - 4 -- Width


a7a :: Float 
a7a = 7 + 5 * sqrt(2)