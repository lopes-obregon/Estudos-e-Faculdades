/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/SQLTemplate.sql to edit this template
 */
/**
 * Author:  renan
 * Created: 2 de mar. de 2022
 */

DROP TABLE IF EXISTS Atletismo;
CREATE TABLE Atletismo(
Id VARCHAR(7) NOT NULL PRIMARY KEY,
Modalidade VARCHAR(25) NOT NULL,
Distancia Varchar(12) NOT NULL);