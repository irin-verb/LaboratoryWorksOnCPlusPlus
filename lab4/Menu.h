#pragma once
#include "Detail.h"
#include "Sensor.h"
#include "Mechanism.h"
#include "Group.h"
#include "Device.h"
#include "Storage.h"

void MainMenu(Storage* Store); //������� ����
void OutputMenu(Storage* Store); //���� ������ (����� ���������)
void DeletionMenu(Storage* Store);//���� �������� (�������� �������)
void AdditionMenu(Storage* Store);//���� ���������� (�������� ����� ��������� �������)
void MovementMenu(Storage* Store);//���� ����������� (���������� ����� ��������� � ������ ������)
void GenerationMenu(Storage* Store);//���� ��������� (��������� ��������� �� �����)

