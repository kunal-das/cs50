-- MySQL dump 10.13  Distrib 5.5.41, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.41-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `transaction` varchar(10) NOT NULL,
  `symbol` varchar(10) NOT NULL,
  `shares` int(20) unsigned NOT NULL,
  `price` decimal(10,2) unsigned NOT NULL,
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (1,22,'BUY','TTM',50,39.10,'2016-11-08 04:35:19'),(3,22,'SELL','FREE',60,1.15,'2016-11-08 04:48:41'),(4,29,'SELL','TTM',100,39.10,'2016-11-08 04:50:28'),(5,22,'BUY','TTM',100,39.10,'2016-11-08 04:51:34'),(6,22,'BUY','AAPL',10,110.41,'2016-11-08 04:53:18'),(7,22,'BUY','APPL',5,110.41,'0000-00-00 00:00:00'),(8,22,'BUY','FREE',100,1.15,'2016-11-08 05:26:48');
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolio`
--

DROP TABLE IF EXISTS `portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolio` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `user_id` int(10) NOT NULL,
  `symbol` varchar(10) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`)
) ENGINE=InnoDB AUTO_INCREMENT=31 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolio`
--

LOCK TABLES `portfolio` WRITE;
/*!40000 ALTER TABLE `portfolio` DISABLE KEYS */;
INSERT INTO `portfolio` VALUES (2,23,'FREE',20),(3,24,'FREE',30),(4,25,'FREE',40),(6,23,'TTM',40),(7,24,'TTM',30),(8,25,'TTM',30),(11,23,'HDB',40),(12,24,'HDB',80),(13,25,'HDB',50),(14,22,'HDB',200),(15,29,'FREE',50),(19,28,'TTM',70),(20,28,'HDB',100),(27,22,'TTM',100),(28,22,'AAPL',10),(29,22,'APPL',5),(30,22,'FREE',100);
/*!40000 ALTER TABLE `portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,2) unsigned NOT NULL DEFAULT '0.00',
  `email` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=35 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS',10000.00,''),(2,'caesar','$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa',10000.00,''),(3,'eli','$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW',10000.00,''),(4,'hdan','$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G',10000.00,''),(5,'jason','$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe',10000.00,''),(6,'john','$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy',10000.00,''),(7,'levatich','$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK',10000.00,''),(8,'rob','$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2',10000.00,''),(9,'skroob','$2y$10$395b7wODm.o2N7W5UZSXXuXwrC0OtFB17w4VjPnCIn/nvv9e4XUQK',10000.00,''),(10,'zamyla','$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e',10000.00,''),(22,'kunal','$2y$10$BKrHfjRgGKN1iYXpfAyXyORSLODTAW1euhKhjYJ7D.vlukPetW76C',16315.90,'kunaldasece@gmail.com'),(23,'kunaldas','$2y$10$nQtbal4Sz/DdZ5Bwi7NWD.4oCWSsTAFVu4RKG4tv8nn7FnaqtHlgC',10000.00,'click2riky@gmail.com'),(24,'chanchal','$2y$10$p2Cc9QKL56M4oezeMWpmPOKAJN13gywgc9hAZQJouozDhkVEFVTU.',10000.00,''),(25,'jaya','$2y$10$hAedq4/ZpqW8YP7.MsP5DOqdhU40QlWoez6AmUMGtfKgoeqdCJmPC',10000.00,''),(26,'Mini','$2y$10$CcOAcVJUUdBPERA8oHJKQOZ/whMyMK7xNor/u8TTK8I0y3XBt.2gm',10000.00,''),(27,'mkdas','$2y$10$NIBM.rLQAfbUVeeohQwxOO/khuZWL8lzP7KZHf1B2.5oU4CUNoU6q',10000.00,''),(28,'rahul','$2y$10$D4VKb9aj.nPqgZHAW/4d4u5AQ41uG.X.uN08YOPhbub/0tyGKUG7i',10115.00,''),(29,'kalra','$2y$10$xd9y5B/Zf2EgrWvtgwFjLeh2Z90A.eK8Lu33D3vsCL/.BYphfyLTK',20832.00,''),(30,'hemraj','$2y$10$ayT9.vTLp41f/PsrrKYuW.cnqGXkP8KIJeIpFh2zqzyOQ5RLaDkUO',10000.00,''),(31,'yewale','$2y$10$qmujLOyIt4/q1aWe3/y4J.bdZTzO04q8NIWCnpIMUtnOn5mW8xzyq',10000.00,''),(32,'kallu','$2y$10$Z8ZaJMkeZbjTTkJqqai90eDm07tv4i20aZ8DL2sMqJx.F.ivTSM82',10000.00,''),(33,'abhay','$2y$10$5E5DXaL2RMRJIaweuI9sAe96yOiQHghoGnQZlf9H1JXtHqso8qRL.',10000.00,''),(34,'bhatti','$2y$10$RPRo715RoGLhafjQ5ObpTekFPd80R2Awg2iAQi8d.s8w1OgcEBAB.',10000.00,'');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-11-16 17:15:14
