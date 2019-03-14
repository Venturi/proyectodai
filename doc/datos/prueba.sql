-- Adminer 3.3.3 MySQL dump

SET NAMES utf8;
SET foreign_key_checks = 0;
SET time_zone = 'SYSTEM';
SET sql_mode = 'NO_AUTO_VALUE_ON_ZERO';

INSERT INTO `Evento` (`IDEvento`, `Nombre`, `IDOrganizador`, `IDLugar`, `IDUbicacion`, `FechaInicio`, `FechaFin`, `Aforo`) VALUES
(1,	'Conferencia sobre Debian GNU/Linux 7.0 \"Wheezy\"',	5,	2,	3,	'2013-06-21',	'2016-06-22',	200),
(3,	'Evento Nuevo',	1,	1,	1,	'2013-06-21',	'2016-06-22',	40),
(5,	'Presentación IPhone 5',	6,	1,	2,	'2013-06-05',	'2013-06-06',	20),
(6,	'Hola',	4,	2,	3,	'2013-06-12',	'2013-06-12',	500),
(7,	'Muerte de Microsoft',	1,	5,	27,	'2013-06-13',	'2013-06-13',	500);

INSERT INTO `ListaVisitantes` (`IDEvento`, `IDVisitante`, `Activo`, `Checked`) VALUES
(7,	14,	0,	0);

INSERT INTO `Lugar` (`IDLugar`, `Nombre`, `Direccion`, `Ciudad`, `Provincia`) VALUES
(1,	'IES Fernando Aguilar Quignón',	'C/Real',	'Cádiz',	'Cádiz'),
(2,	'Liceo del Sagrado Corazón',	'C/ Real, 225',	'San Fernando',	'Cádiz'),
(3,	'Compañía de María',	'C/Real',	'San Fernando',	'Cádiz'),
(4,	'Estadio Ramón de Carranza',	'Plaza Madrid',	'Cádiz',	'Cádiz'),
(5,	'Ubicación Definitiva',	'Avenida Azeroth',	'Sodoma',	'Gomorra');

INSERT INTO `Organizador` (`IDOrganizador`, `CIFNIF`, `Nombre`, `NombreContacto`, `Telefono`, `Email`) VALUES
(1,	'4889566W',	'Venturi Software',	'Venturi',	'695666704',	'venturi.debian@gmail.com'),
(4,	'48899570W',	'Hermes Interactiva S.L.',	'Dani',	'+34902902902',	'emailinventado1@hotmail.com'),
(5,	'48899568W',	'Federico Industries',	'Federico',	'956949494',	'federicoindustries@hotmail.com'),
(6,	'48899569W',	'Ryu Hayabusa Enterprises',	'Ken Masters',	'956909090',	'ryuhayabusa@hotmail.com');

INSERT INTO `Ubicaciones` (`IDUbicacion`, `Nombre`, `MaxAforo`, `IDLugar`) VALUES
(1,	'Aula 1',	80,	1),
(2,	'Aula 4',	30,	1),
(3,	'Salón de Actos',	500,	2),
(17,	'Salón de Actos',	300,	3),
(24,	'Gimnasio',	500,	3),
(25,	'Hola',	10,	3),
(26,	'Sala de Prensa',	100,	4),
(27,	'Stormwind',	1000,	5),
(28,	'Ironforge',	900,	5),
(29,	'Aula 3',	40,	1);

INSERT INTO `ValidaReserva` (`IDVisitante`, `IDEvento`, `MD5`, `Fin`) VALUES
(14,	7,	'072cd9a1a09767f3ce7ce6a143e27e05',	'2013-06-14 22:20:31');

INSERT INTO `Visitante` (`IDVisitante`, `Nombre`, `Apellido1`, `Apellido2`, `DNI`, `EMail`) VALUES
(14,	'Manuel',	'Porras',	'Peralta',	'48899566W',	'venturi.debian@gmail.com');

-- 2013-06-14 04:16:33
