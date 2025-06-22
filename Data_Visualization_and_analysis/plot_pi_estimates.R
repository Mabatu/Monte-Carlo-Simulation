# Install ggplot2 only once, you can skip it after first run
# install.packages("ggplot2")

library("ggplot2")

myPi.data <- read.csv(file="Path\\to\\data.csv")
summary(myPi.data)
head(myPi.data)
p1 <- ggplot() + geom_line(aes(y = Estimate.Pi, x = ITERATION),
                           color="orange", 
                           linewidth=1, 
                           linetype=1,
                           data = myPi.data) +                    
  geom_hline(yintercept = pi, color = "blue", linetype = 1, size = 1) +
  labs(
    title = "Estimate of Pi vs iterations",
    x = "Iterations",
    y = "Estimate Pi",
    caption = "Horizontal line at π"
  )

p1
