


library(ggplot2)
  
data <- data.frame(name = c('P1', 'P2', 'P3', 'P4'), 
                   start = c(2, 5, 0, 18),
                   end = c(5, 13, 2, 38)
)

ggplot(data, aes(x=start, xend=end, y=name, yend=name)) +
  theme_bw()+
  geom_segment(size=8) + 
  labs(title='SJF', x='Time', y='Processes')