clear all
close all
clc

% Abrir un cuadro de diálogo con los posibles archivos a seleccionar dentro
% de la carpetaLa extra
imagen = uigetfile({'*.jpg; *.png'});
%La Imagen
img = imread(imagen);
%Cambiar a grises
gris = rgb2gray(img);

%% Espacio de color RGB
% A partir de los tres colores "básicos" (primarios) se pueden generar
% muchos otros, por lo que estos tres colores determinan el espacio de
% colores. Se puede ver este espacio como una especie de cubo con
% coordenadas cartesianas tridimensionales
rojo = uint8(zeros(size(img)));
rojo(:,:,1) = img(:,:,1);
verde = uint8(zeros(size(img)));
verde(:,:,2) = img(:,:,2);
azul = uint8(zeros(size(img)));
azul(:,:,3) = img(:,:,3);

% Mostrar en una sola imagen
figure(1)
subplot(221), imshow(img)
subplot(222), imshow(rojo)
subplot(223), imshow(verde)
subplot(224), imshow(azul)

%% Modelo de color HSV
% Hue Saturation Value, Matiz, Saturación, Valor
% Se trata de una transformación no lineal del espacio de color RGB. Este
% modelo de color a diferencia del espacio RGB se puede ver como un cono,
% donde se representa:
% Matiz, es el ángulo de la cara del cono, por lo que tendrá valores de 0°
% a 360° (que también se toma de 0 a 100%), donde cada valor representa un
% color
% Saturación, representa como la distancia al eje del cono,
% Valor es la altura en el eje blanco negro

% Convertir de espacio RGB a HSV
hsv = rgb2hsv(img);
figure(2)
subplot(221), imshow(hsv)
subplot(222), imshow(hsv(:,:,1))
subplot(223), imshow(hsv(:,:,2))
subplot(224), imshow(hsv(:,:,3))

%% Modelo de color YcBcT
data_YCBCR = rgb2ycbcr(img);
% Este formato codifica la luminosidad, la cromancia (esto es la
% información del color de la imagen)
% Una vez que se convierte la imagen "data_YCBCR" es un arreglo
% tridimensional, del estilo M x N x 3, donde:
% M - ancho de la imagen
% N - alto de la imagen
% y las 3 capas son:
% (1) Luminancia Y (componente de luminosidad)
%   Y = 0.299 R + 0.587 G + 0.114 B
% (2) Crominancia Cb (diferencia de azul)
% (3) Crominancia Cr (diferencia de rojo)
figure(3)
subplot(221), imshow(data_YCBCR, [])
subplot(222), imshow(data_YCBCR(:,:,1), [])
subplot(223), imshow(data_YCBCR(:,:,2), [])
subplot(224), imshow(data_YCBCR(:,:,3), [])

%% Modelo de color CIE 1931 XYZ
% Es uno de los primeros espacios de color definidos matemáticamente. 
% La idea es que el concepto de color puede ser dividido en dos partes:
% brillo y cromaticidad. Por parte del brillo, se considera por ejemplo que
% el color blanco es un color brillante mientras que el gris es una forma
% menos brillante del blanco, lo que indica que lo que cambia es el brillo
% no la cromaticidad.
data_XYZ = rgb2xyz(img);
figure(4)
subplot(221), imshow(data_XYZ, [])
subplot(222), imshow(data_XYZ(:,:,1), [])
subplot(223), imshow(data_XYZ(:,:,2), [])
subplot(224), imshow(data_XYZ(:,:,3), [])

%% Modelo de color NTSC
% Sistema de color del Comité Nacional de Sistema de Televisión, un sistema
% de televisión analógico que se empleaba en América y Japón a diferencia
% del PAL que se empleaba en Europa.
data_ntsc = rgb2ntsc(img);
figure(5)
subplot(221), imshow(data_ntsc, [])
subplot(222), imshow(data_ntsc(:,:,1), [])
subplot(223), imshow(data_ntsc(:,:,2), [])
subplot(224), imshow(data_ntsc(:,:,3), [])