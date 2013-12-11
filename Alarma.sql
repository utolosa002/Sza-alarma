
-- phpMyAdmin SQL Dump
-- version 3.5.2.2
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tiempo de generación: 05-12-2013 a las 22:15:32
-- Versión del servidor: 5.1.66
-- Versión de PHP: 5.2.17

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `u819845947_alarm`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `Alarma`
--

CREATE TABLE IF NOT EXISTS `Alarma` (
  `idalarma` tinyint(1) NOT NULL AUTO_INCREMENT,
  `aizena` text NOT NULL,
  `aegoera` tinyint(1) NOT NULL DEFAULT '0',
  `jabeiderab` tinyint(1) NOT NULL,
  PRIMARY KEY (`idalarma`),
  KEY `idalarma` (`idalarma`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=13 ;

--
-- Volcado de datos para la tabla `Alarma`
--

INSERT INTO `Alarma` (`idalarma`, `aizena`, `aegoera`,`jabeiderab`) VALUES
(0, 'proba0', 1, 6),
(8, 'konpartitua', 0, 1),
(2, 'Etxea', 0,2),
(3, 'Etxea', 0,3),
(9, 'asfADF', 0,1),
(6, 'proba6', 1,5),
(10, 'Alarma izena', 1,1),
(11, 'Alarma izena', 0,1),
(12, 'eerrerer', 0,4);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `erabiltzaile`
--

CREATE TABLE IF NOT EXISTS `Erabiltzaile` (
  `iderab` int(5) NOT NULL AUTO_INCREMENT,
  `nicka` varchar(45) DEFAULT NULL,
  `emaila` varchar(45) DEFAULT NULL,
  `pasahitza` varchar(45) DEFAULT NULL,
  `azkenkonexioa` text NOT NULL,
  PRIMARY KEY (`iderab`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=13 ;

--
-- Volcado de datos para la tabla `erabiltzaile`
--

INSERT INTO `Erabiltzaile` (`iderab`, `nicka`, `emaila`, `pasahitza`, `azkenkonexioa`) VALUES
(1, 'admin', 'tolosa0@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', '2013-12-4'),
(2, 'odei', 'odei@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', '2013-11-9'),
(3, 'unai', 'tolosa1@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', '2013-12-3'),
(4, 'odeiodei', 'odei2@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', '2013-12-3'),
(5, 'proba', 'proba@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', 'Ez da inoiz konektatu'),
(6, 'unaiunai', 'tolosa2@proba.com', 'd033e22ae348aeb5660fc2140aec35850c4da997', 'Ez da inoiz konektatu'),
(12, 'Erabiltzailea', 'g@gs.rh', 'd033e22ae348aeb5660fc2140aec35850c4da997', 'Ez da inoiz konektatu');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `erab_alarma`
--

CREATE TABLE IF NOT EXISTS `Erab_alarma` (
  `iderab` int(11) NOT NULL,
  `idalarma` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `erab_alarma`
--

INSERT INTO `Erab_alarma` (`iderab`, `idalarma`) VALUES
(1, 8),
(1, 9),
(1, 10),
(1, 11),
(2, 2),
(2, 8),
(3, 8),
(3, 3),
(5, 6),
(4, 12),
(6, 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `Sentsore`
--

CREATE TABLE IF NOT EXISTS `Sentsore` (
  `sid` int(11) NOT NULL AUTO_INCREMENT,
  `idalarma` int(11) NOT NULL,
  `sizena` text NOT NULL,
  `segoera` int(11) NOT NULL,
  PRIMARY KEY (`Sid`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=33 ;

--
-- Volcado de datos para la tabla `Sentsore`
--

INSERT INTO `Sentsore` (`sid`, `idalarma`, `sizena`, `segoera`) VALUES
(0, 6, 'proba', 1),
(26, 9, 'AVDAF', 0),
(27, 9, 'FDA', 1),
(28, 10, 'vcbcb', 0),
(6, 2, 'pasilloa1', 1),
(7, 2, 'pasilloa2', 0),
(8, 2, 'gela1', 0),
(9, 2, 'gela2', 0),
(10, 3, 'gela1', 1),
(11, 3, 'pasilloa1', 1),
(32, 8, 'gqergqe', 1),
(16, 6, 'proba', 1),
(31, 8, 'afv', 1);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
