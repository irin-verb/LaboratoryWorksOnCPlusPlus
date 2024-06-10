#pragma once
#include "Detail.h"
#include "Sensor.h"
#include "Mechanism.h"
#include "Group.h"
#include "Device.h"
#include "Storage.h"

void MainMenu(Storage* Store); //главное меню
void OutputMenu(Storage* Store); //меню вывода (вывод сущностей)
void DeletionMenu(Storage* Store);//меню удаления (удаление изделий)
void AdditionMenu(Storage* Store);//меню добавления (внесение новых сущностей вручную)
void MovementMenu(Storage* Store);//меню перемещения (добавление одних элементов в состав других)
void GenerationMenu(Storage* Store);//меню генерации (случайных сущностей на склад)

