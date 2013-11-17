-- phpMyAdmin SQL Dump
-- version 4.0.6deb1
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tiempo de generación: 10-11-2013 a las 11:36:58
-- Versión del servidor: 5.5.34-0ubuntu0.13.10.1
-- Versión de PHP: 5.5.3-1ubuntu2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `Alarma`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `Alarma`
--

CREATE TABLE IF NOT EXISTS `Alarma` (
  `alarmaid` tinyint(1) NOT NULL AUTO_INCREMENT,
  `aizena` text NOT NULL,
  `aegoera` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`alarmaid`),
  KEY `alarmaid` (`alarmaid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `Alarma`
--

INSERT INTO `Alarma` (`alarmaid`, `aizena`, `aegoera`) VALUES
(0, 'proba0', 1),
(1, 'Etxea', 0),
(2, 'Etxea', 0),
(3, 'Etxea', 0),
(4, 'Lantegia', 0),
(6, 'proba6', 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `erabiltzaile`
--

CREATE TABLE IF NOT EXISTS `erabiltzaile` (
  `iderab` int(5) NOT NULL AUTO_INCREMENT,
  `nicka` varchar(45) DEFAULT NULL,
  `emaila` varchar(45) DEFAULT NULL,
  `pasahitza` varchar(45) DEFAULT NULL,
  `azkenkonexioa` text NOT NULL,
  PRIMARY KEY (`iderab`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=8 ;

--
-- Volcado de datos para la tabla `erabiltzaile`
--

INSERT INTO `erabiltzaile` (`iderab`, `nicka`, `emaila`, `pasahitza`, `azkenkonexioa`) VALUES
(1, 'admin', 'tolosa0@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', '2013-11-10'),
(2, 'odei', 'odei@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', '2013-11-9'),
(3, 'unai', 'tolosa1@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', '2013-11-10'),
(4, 'Odeiodei', 'odei2@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', '2013-11-7'),
(5, 'proba', 'proba@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', 'Ez da inoiz konektatu'),
(6, 'unaiunai', 'tolosa2@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', 'Ez da inoiz konektatu');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `erab_alarma`
--

CREATE TABLE IF NOT EXISTS `erab_alarma` (
  `iderab` int(11) NOT NULL,
  `alarma` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `erab_alarma`
--

INSERT INTO `erab_alarma` (`iderab`, `alarma`) VALUES
(1, 1),
(2, 2),
(3, 3),
(1, 4),
(2, 4),
(3, 4),
(5, 6);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `Sentsore`
--

CREATE TABLE IF NOT EXISTS `Sentsore` (
  `Sid` int(11) NOT NULL AUTO_INCREMENT,
  `Jalarma` int(11) NOT NULL,
  `Sizena` text NOT NULL,
  `Segoera` int(11) NOT NULL,
  PRIMARY KEY (`Sid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `Sentsore`
--

INSERT INTO `Sentsore` (`Sid`, `Jalarma`, `Sizena`, `Segoera`) VALUES
(0, 6, 'proba', 1),
(1, 1, 'Egongela', 1),
(2, 1, 'pasilloa1', 0),
(3, 1, 'pasilloa2', 1),
(4, 1, 'gela1', 0),
(5, 1, 'gela2', 1),
(6, 2, 'pasilloa1', 1),
(7, 2, 'pasilloa2', 0),
(8, 2, 'gela1', 0),
(9, 2, 'gela2', 0),
(10, 3, 'gela1', 1),
(11, 3, 'pasilloa1', 1),
(12, 4, 'Idazkaritza', 0),
(13, 4, 'ofizina1', 1),
(14, 4, 'ofizina2', 0),
(15, 4, 'pasilloa', 1),
(16, 6, 'proba', 1);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
