-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- 主机： db
-- 生成日期： 2021-04-27 12:57:29
-- 服务器版本： 8.0.23
-- PHP 版本： 7.4.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 数据库： `SeatU`
--

-- --------------------------------------------------------

--
-- 表的结构 `Seats`
--

CREATE TABLE `Seats` (
  `SeatID` int NOT NULL,
  `TableID` int NOT NULL,
  `State` int NOT NULL,
  `LastCheckTime` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- 转存表中的数据 `Seats`
--

INSERT INTO `Seats` (`SeatID`, `TableID`, `State`, `LastCheckTime`) VALUES
(1, 1, 1, '2021-04-27 20:57:27'),
(2, 1, 2, '2021-04-27 20:57:27'),
(3, 1, 2, '2021-04-27 20:57:27'),
(4, 1, 2, '2021-04-27 20:57:27');

-- --------------------------------------------------------

--
-- 表的结构 `SensorData`
--

CREATE TABLE `SensorData` (
  `DeviceID` int NOT NULL,
  `TableID` int NOT NULL,
  `US_Mean` float NOT NULL,
  `IR_Mean` float NOT NULL,
  `US_Var` float NOT NULL,
  `IR_Var` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- 转存表中的数据 `SensorData`
--

INSERT INTO `SensorData` (`DeviceID`, `TableID`, `US_Mean`, `IR_Mean`, `US_Var`, `IR_Var`) VALUES
(1, 1, 52.72, 120, 2, 0),
(2, 1, 90, 90, 2, 3),
(3, 1, 50, 40, 60, 70),
(4, 1, 30, 40, 3, 4);

-- --------------------------------------------------------

--
-- 表的结构 `Tables`
--

CREATE TABLE `Tables` (
  `TableID` int NOT NULL,
  `DeviceID` int NOT NULL,
  `LastCheckTime` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- 表的结构 `Users`
--

CREATE TABLE `Users` (
  `IntlID` varchar(50) NOT NULL,
  `Password` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- 转储表的索引
--

--
-- 表的索引 `Seats`
--
ALTER TABLE `Seats`
  ADD PRIMARY KEY (`SeatID`,`TableID`);

--
-- 表的索引 `SensorData`
--
ALTER TABLE `SensorData`
  ADD PRIMARY KEY (`TableID`,`DeviceID`) USING BTREE;

--
-- 表的索引 `Tables`
--
ALTER TABLE `Tables`
  ADD PRIMARY KEY (`TableID`);

--
-- 表的索引 `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`IntlID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
