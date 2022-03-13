
















library(ggplot2)
  
data <- data.frame(name = c('P1', 'P2', 'P3', 'P4', 'P5'), 
                   start = c(0, 5, 0, 18, 13),
                   end = c(5, 13, 2, 38, 18)
)

ggplot(data, aes(x=start, xend=end, y=name, yend=name)) +
  theme_bw()+
  geom_segment(size=8) + 
  labs(title='RR 5ms', x='Time', y='Processes')