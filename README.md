# FdF
FDF — это проект 42 для изучения 3D-программирования.

Программа берет карту в качестве параметра и создает ее трехмерное представление. 
Рендеринг 3D-карты из 2D-представления. Вы можете двигать, вращать, увеличивать коэффициент высоты и увеличивать / уменьшать масштаб. 

Все преобразования выполняются через преобразования матриц, кроме преобразования изображения.

Программа представляет собой модель в изометрической проекции.

Этот проект посвящен созданию простой каркасной модели трехмерного ландшафта путем соединения различных точек (x, y, z) с помощью линейных сегментов (ребер).

Координаты ландшафта хранятся в файле .fdf, передаваемом в качестве параметра
ваша программа. Вот пример:

$>cat 42.fdf
```
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0

0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0

0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0

0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0

0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0

0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0

0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```
Каждое число представляет собой точку в пространстве:

- Горизонтальное положение соответствует его оси.
- Вертикальное положение соответствует его ординате.
- Значение соответствует его высоте
## Визуализация
![alt-текст](https://i.postimg.cc/jSkj7HNn/1.png)
