# https://candela.readthedocs.io/en/latest/index.html
library(candela)

data <- list(
  list(name='P1', level=1, start=0, end=3),
  list(name='P2', level=1, start=3, end=11),
  list(name='P3', level=1, start=11, end=13),
  list(name='P4', level=1, start=13, end=33),
  list(name='P5', level=1, start=33, end=38) )
  

candela('GanttDiagramm',
        data=data, label='name',
        start='start', end='end', level='level',
        width=700, height=200)