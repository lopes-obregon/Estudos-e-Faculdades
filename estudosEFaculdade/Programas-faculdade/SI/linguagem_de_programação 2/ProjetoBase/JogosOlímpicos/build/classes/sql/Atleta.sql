/* 
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/SQLTemplate.sql to edit this template
 */
/**
 * Author:  renan
 * Created: 22 de fev. de 2022
 */

drop table if exists Atleta;
create table Atleta(
CPF varchar(15) not null primary key,
Nome varchar(50) not null,
Nacao varchar(15) not null);