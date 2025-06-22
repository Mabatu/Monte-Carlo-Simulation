# Install ggplot2 only once; you can skip it after the first run
# install.packages("ggplot2")
library(ggplot2)
library("ggplot2")

#Choose the CSV file with the greatest iterations.
myPi.data <- read.csv(file="Path\\To\\outFile.csv")
summary(myPi.data)
head(myPi.data)
p1 <- ggplot() + geom_line(aes(y = abs(pi-Estimate.Pi), x = ITERATION),
                           color="red", 
                           linewidth=1, 
                           linetype=1,
                           data = myPi.data) +                    
  geom_hline(yintercept = 0, color = "blue", linetype = 1, size = 1) +
  labs(
    title = "ERROR vs ITERATIONS",
    x = "ITERATIONS",
    y = "ERROR",
    caption = "Horizontal line at 0"
  )
p1
