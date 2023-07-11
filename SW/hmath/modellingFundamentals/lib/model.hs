module Model (
-- Exponential Growth Model

) where 

gotelli :: Floating a => a -> a -> a -> a
gotelli lambda n0 t =
    (lambda**t)*n0