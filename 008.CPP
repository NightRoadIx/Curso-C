/*
  Curso de Programaci¢n
  Lección 8
*/

/*
	Los apuntadores son un tipo de variable especial en el lenguaje de programación C,
	Se trata de variables que no guardan exactamente un dato en memoria, sino que almacena
	la dirección de memoria ya sea de otra variable o segmento de código.
	
	Para el caso de las computadoras, la memoria del programa (memoria volátil o de acceso aleatorio, RAM)
	está "mezclada" con la memoria de datos, a esto se le conoce como arquitectura Von Neumann.
	Cuando el programa es cargado en dicha memoria, cada parte del mismo programa y de los datos que utiliza
	se almacenan en localidades de memoria que pueden ser vistas como cajas o compartimentos, identificados por
	un número, el cual es su dirección, es ahí donde los apuntadores entran en juego al tener la capacidad de
	almacenar dichos valores y poder "acceder" de manera indirecta al contenido de esos espacios.
	
	En los siguientes programas PUNTx.cpp se irán describiendo algunas de las particularidades de los apuntadores
	y sus usos más comúnes.
	
*/