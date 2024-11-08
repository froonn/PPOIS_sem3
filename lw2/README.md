
1. `Employee` (Сотрудник) - базовый класс +
2. `Technician` (Техник) - наследует от `Employee` +
3. `Manager` (Менеджер) - наследует от `Employee` +
4. `Electrician` (Электрик) - наследует от `Technician` 
5. `Plumber` (Сантехник) - наследует от `Technician` +
6. `Carpenter` (Плотник) - наследует от `Technician`
7. `ProjectManager` (Проектный менеджер) - наследует от `Manager`
8. `HRManager` (Менеджер по персоналу) - наследует от `Manager`
9. `FinanceManager` (Финансовый менеджер) - наследует от `Manager`
10. `RepairCompany` (Фирма по ремонту) - использует множественное наследование и виртуальное наследование
11. `Client` (Клиент) - класс для представления клиентов фирмы
12. `ServiceRequest` (Заявка на обслуживание) - класс для представления заявок на ремонт
13. `Invoice` (Счёт) - класс для представления счетов за услуги
14. `Receptionist` (Администратор) - наследует от `Employee`
15. `Supervisor` (Супервайзер) - наследует от `Manager`
16. `ITSupport` (ИТ поддержка) - наследует от `Technician`
17. `QualityInspector` (Инспектор качества) - наследует от `Technician`
18. `WarehouseManager` (Менеджер склада) - наследует от `Manager`

