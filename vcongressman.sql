-- Configuración de la base de datos de Venturi Congress Man

SET NAMES utf8;
SET foreign_key_checks = 0;
SET time_zone = 'SYSTEM';
SET sql_mode = 'NO_AUTO_VALUE_ON_ZERO';

DROP DATABASE vcongressman;
CREATE DATABASE vcongressman;

GRANT ALL PRIVILEGES ON `vcongressman`.* TO 'vcmuser'@'localhost' IDENTIFIED BY 'vcmuser';

USE vcongressman;

DROP TABLE IF EXISTS `Evento`;
CREATE TABLE `Evento` (
  `IDEvento` int(4) NOT NULL AUTO_INCREMENT COMMENT 'ID único del Evento',
  `Nombre` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `IDOrganizador` int(4) NOT NULL,
  `IDLugar` int(4) NOT NULL,
  `IDUbicacion` int(5) NOT NULL,
  `FechaInicio` date NOT NULL,
  `FechaFin` date NOT NULL,
  `Aforo` int(4) NOT NULL,
  PRIMARY KEY (`IDEvento`),
  KEY `IDOrganizador` (`IDOrganizador`),
  KEY `IDLugar` (`IDLugar`),
  KEY `IDUbicacion` (`IDUbicacion`),
  CONSTRAINT `Evento_ibfk_1` FOREIGN KEY (`IDUbicacion`) REFERENCES `Ubicaciones` (`IDUbicacion`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `Evento_LugarFK` FOREIGN KEY (`IDLugar`) REFERENCES `Lugar` (`IDLugar`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `Evento_OrganizadorFK` FOREIGN KEY (`IDOrganizador`) REFERENCES `Organizador` (`IDOrganizador`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci COMMENT='Tabla de Eventos del PI';

DROP TABLE IF EXISTS `ListaVisitantes`;
CREATE TABLE `ListaVisitantes` (
  `IDEvento` int(4) NOT NULL,
  `IDVisitante` int(6) NOT NULL,
  `Activo` tinyint(1) NOT NULL DEFAULT '0',
  `Checked` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`IDEvento`,`IDVisitante`),
  KEY `IDVisitante` (`IDVisitante`),
  CONSTRAINT `ListaVisitantes_ibfk_1` FOREIGN KEY (`IDEvento`) REFERENCES `Evento` (`IDEvento`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `ListaVisitantes_ibfk_3` FOREIGN KEY (`IDVisitante`) REFERENCES `Visitante` (`IDVisitante`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci COMMENT='Relaciona Evento con Visitante';

DROP TABLE IF EXISTS `Lugar`;
CREATE TABLE `Lugar` (
  `IDLugar` int(3) NOT NULL AUTO_INCREMENT,
  `Nombre` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `Direccion` varchar(200) COLLATE utf8_spanish_ci NOT NULL,
  `Ciudad` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `Provincia` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`IDLugar`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

DROP TABLE IF EXISTS `Organizador`;
CREATE TABLE `Organizador` (
  `IDOrganizador` int(4) NOT NULL AUTO_INCREMENT,
  `CIFNIF` varchar(9) COLLATE utf8_spanish_ci NOT NULL,
  `Nombre` varchar(40) COLLATE utf8_spanish_ci NOT NULL,
  `NombreContacto` varchar(120) COLLATE utf8_spanish_ci NOT NULL,
  `Telefono` varchar(20) COLLATE utf8_spanish_ci DEFAULT NULL,
  `Email` varchar(100) COLLATE utf8_spanish_ci DEFAULT NULL,
  PRIMARY KEY (`IDOrganizador`),
  UNIQUE KEY `IDOrganizador` (`IDOrganizador`),
  UNIQUE KEY `CIF/NIF` (`CIFNIF`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci COMMENT='Tabla de Organizadores de Eventos';

DROP TABLE IF EXISTS `Ubicaciones`;
CREATE TABLE `Ubicaciones` (
  `IDUbicacion` int(5) NOT NULL AUTO_INCREMENT,
  `Nombre` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  `MaxAforo` int(4) NOT NULL,
  `IDLugar` int(4) NOT NULL,
  PRIMARY KEY (`IDUbicacion`),
  KEY `IDLugar` (`IDLugar`),
  CONSTRAINT `Ubicaciones_ibfk_1` FOREIGN KEY (`IDLugar`) REFERENCES `Lugar` (`IDLugar`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;

DROP TABLE IF EXISTS `ValidaReserva`;
CREATE TABLE `ValidaReserva` (
  `IDVisitante` int(6) NOT NULL,
  `IDEvento` int(4) NOT NULL,
  `MD5` varchar(32) COLLATE utf8_spanish_ci NOT NULL,
  `Fin` datetime NOT NULL,
  PRIMARY KEY (`IDVisitante`,`IDEvento`),
  UNIQUE KEY `MD5` (`MD5`),
  KEY `IDEvento` (`IDEvento`),
  CONSTRAINT `ValidaReserva_ibfk_1` FOREIGN KEY (`IDVisitante`) REFERENCES `Visitante` (`IDVisitante`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `ValidaReserva_ibfk_2` FOREIGN KEY (`IDEvento`) REFERENCES `Evento` (`IDEvento`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci COMMENT='Tabla de MD5 de validaciones de reserva de plaza en los eventos';

DROP TABLE IF EXISTS `Visitante`;
CREATE TABLE `Visitante` (
  `IDVisitante` int(6) NOT NULL AUTO_INCREMENT,
  `Nombre` varchar(40) COLLATE utf8_spanish_ci NOT NULL,
  `Apellido1` varchar(40) COLLATE utf8_spanish_ci NOT NULL,
  `Apellido2` varchar(40) COLLATE utf8_spanish_ci DEFAULT NULL,
  `DNI` varchar(9) COLLATE utf8_spanish_ci NOT NULL,
  `EMail` varchar(100) COLLATE utf8_spanish_ci NOT NULL,
  PRIMARY KEY (`IDVisitante`),
  UNIQUE KEY `IDVisitante` (`IDVisitante`,`DNI`,`EMail`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish_ci;
