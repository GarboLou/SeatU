-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Host: db
-- Generation Time: Apr 21, 2021 at 12:04 PM
-- Server version: 8.0.23
-- PHP Version: 7.4.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `SeatU`
--

-- --------------------------------------------------------

--
-- Table structure for table `Seats`
--

CREATE TABLE `Seats` (
  `SeatID` int NOT NULL,
  `TableID` int NOT NULL,
  `State` int NOT NULL,
  `LastCheckTime` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `Seats`
--

INSERT INTO `Seats` (`SeatID`, `TableID`, `State`, `LastCheckTime`) VALUES
(0, 1, 2, '2021-04-21 12:01:14'),
(1, 1, 0, '2021-04-21 19:49:02'),
(2, 1, 0, '2021-04-21 12:01:14'),
(3, 1, 1, '2021-04-21 12:02:11');

-- --------------------------------------------------------

--
-- Table structure for table `SensorData`
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
-- Dumping data for table `SensorData`
--

INSERT INTO `SensorData` (`DeviceID`, `TableID`, `US_Mean`, `IR_Mean`, `US_Var`, `IR_Var`) VALUES
(1, 1, 123, 456, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `Tables`
--

CREATE TABLE `Tables` (
  `TableID` int NOT NULL,
  `DeviceID` int NOT NULL,
  `LastCheckTime` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Seats`
--
ALTER TABLE `Seats`
  ADD PRIMARY KEY (`SeatID`,`TableID`);

--
-- Indexes for table `SensorData`
--
ALTER TABLE `SensorData`
  ADD PRIMARY KEY (`TableID`,`DeviceID`) USING BTREE;

--
-- Indexes for table `Tables`
--
ALTER TABLE `Tables`
  ADD PRIMARY KEY (`TableID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
