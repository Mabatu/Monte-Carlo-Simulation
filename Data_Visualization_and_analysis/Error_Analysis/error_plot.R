# Install ggplot2 only once, you can skip it after first run
# install.packages("ggplot2")
library(ggplot2)
library("ggplot2")

myPi.data <- read.csv(file="C:\\Users\\user\\Desktop\\R\\10000000_iterations.csv")
summary(myPi.data)
head(myPi.data)
p1 <- ggplot() + geom_line(aes(y = pi-Estimate.Pi, x = ITERATION),
                           color="red", 
                           linewidth=1, 
                           linetype=1,
                           data = myPi.data) +                    
  geom_hline(yintercept = 0, color = "blue", linetype = 1, size = 1) +
  labs(
    title = "Estimate of Pi vs iterations",
    x = "ITERATIONS",
    y = "ERROR",
    caption = "Horizontal line at 0"
  )

p1

