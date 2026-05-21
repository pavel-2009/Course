# Course

# Track 1 — Linux, Networks & Low-Level Fundamentals

**Длительность:** 10 недель (2.5 месяца)  
**Цель:**
- Уверенно работать в Linux без GUI
- Понимать сети на уровне пакетов
- Освоить основы C и указатели

**Формат:**  
6 дней учёбы + 1 день практики/отдыха

---

# Week 1–2 — Linux Mastery

## Day 1 — Установка Ubuntu Server

# Already done

### Темы
- Установка Ubuntu Server
- Базовая настройка системы
- Настройка SSH

### Практика
```bash
sudo apt update && sudo apt upgrade -y
```

Настроить SSH-доступ.

---

## Day 2 — Файловая система и навигация

# Already done

### Команды
```bash
ls -la
tree
cd
pwd
mkdir -p
touch
```

---

## Day 3 — Работа с файлами

# Already done

### Команды
```bash
cp
mv
rm -rf
cat
less
nano
vim
```

---

## Day 4 — Поиск и фильтрация

# Already done

### Команды
```bash
find
grep -r
locate
which
whereis
```

---

## Day 5 — Права доступа и пользователи

# Already done

### Команды
```bash
chmod
chown
sudo
adduser
su -
```

### Файлы
```text
/etc/passwd
```

---

## Day 6 — Процессы и логи

# Already done

### Команды
```bash
ps aux
top
htop
kill
journalctl
tail -f
```

---

## Day 7 — Практика

# Already done

### Задание
Написать скрипт, который:
- находит `.log` файлы старше 30 дней;
- архивирует их.

### Дополнительно
Настроить систему для работы только с клавиатуры.

---

# Week 3–4 — Bash Scripting & Automation

## Day 8 — Переменные и условия

# Already done

### Задание
Написать скрипт с:
```bash
if [ -f $1 ]
```

---

## Day 9 — Циклы и функции

### Задание
Создать скрипт обработки списка файлов.

---

## Day 10 — Работа с текстом

### Инструменты
```bash
awk
sed
cut
```

### Задание
Распарсить:
```bash
ip a
```

Вывести только IP-адреса.

---

## Day 11 — Пайпы и перенаправления

### Команды
```bash
command > file 2>&1
tee
xargs
```

---

## Day 12 — curl + jq

### Задание
Получить данные с API и красиво вывести.

---

## Day 13 — cron & systemd timers

### Задание
Настроить автозапуск скрипта.

---

## Day 14 — Практика

### Задание
Создать скрипт мониторинга сайта каждые 5 минут.

---

# Week 5–6 — Основы сетей

## Day 15 — OSI и TCP/IP

### Задание
Нарисовать модели и объяснить каждый уровень.

---

## Day 16 — IP-адресация и Subnetting

### Задание
Решить 10 задач по CIDR/subnetting.

---

## Day 17 — ARP, ICMP и TCP Handshake

### Инструменты
```bash
tcpdump
arping
ping
```

---

## Day 18 — Маршрутизация и NAT

### Команды
```bash
ip route
```

Включить IP forwarding.

---

## Day 19 — DNS

### Инструменты
```bash
dig
```

### Файлы
```text
/etc/hosts
```

### Дополнительно
Настроить `dnsmasq`.

---

## Day 20 — iptables / nftables

### Задание
Разрешить только:
- SSH
- HTTP

---

## Day 21 — Практика

### Задание
Настроить:
- NAT
- Port Forwarding

между виртуальными машинами.

---

# Week 7–8 — Продвинутые сети и безопасность

## Day 22 — WireGuard VPN

### Задание
Полная настройка:
- сервера;
- клиента.

---

## Day 23 — SSH Hardening

### Темы
- SSH keys
- Fail2Ban
- Отключение root login

---

## Day 24 — Wireshark

### Задание
Разобрать:
- TCP handshake;
- HTTP traffic.

---

## Day 25 — Nmap

### Команды
```bash
nmap -sV -O
```

---

## Day 26 — Сокеты в Python

### Задание
Создать TCP echo server.

---

## Day 27 — Практика

### Задание
Собрать домашнюю лабораторию:
```text
Router → Linux Server → VM
```

---

## Day 28 — Повторение

Повторить сети и подготовиться к C.

---

# Week 9–10 — C Programming

## Day 29 — Компиляция и Makefile

### Задание
- Hello World
- argc/argv

### Флаги
```bash
-Wall -Wextra -Werror
```

---

## Day 30 — Указатели

### Задание
Реализовать `swap()` через указатели.

---

## Day 31 — Массивы и строки

### Задание
Реализовать:
- `strlen`
- `strcpy`

---

## Day 32 — Динамическая память

### Темы
```c
malloc
free
```

### Задание
Создать динамический массив.

---

## Day 33 — Структуры

### Задание
```c
struct Student
```

---

## Day 34 — Linked List

### Функции
- push
- print
- free

---

## Day 35 — Финальная практика

### Задание
Создать:
- калькулятор;
- парсер простых выражений.

---

# Чек-лист завершения Track 1

- [ ] Уверенно работаю в Linux без GUI
- [ ] Комфортно пишу bash-скрипты
- [ ] Понимаю сети на уровне пакетов
- [ ] Настроил WireGuard и SSH keys
- [ ] Уверенно работаю с указателями и памятью в C
- [ ] Написал минимум один проект на C

## Проекты
- Мини-калькулятор
- Парсер
- Реализация linked list





# Track 2 — Алгоритмы и Структуры Данных

**Длительность:** 12 недель (3 месяца)  
**Цель:**
- Достичь уверенного уровня по DSA
- Подготовиться к техническим собеседованиям
- Усилить математическое и алгоритмическое мышление

**Формат:**  
6 дней учёбы + 1 день отдыха/контестов

---

# Week 1–2 — Arrays, Hash Tables & Two Pointers

## Day 1 — Big O & Complexity

### Темы
- Time Complexity
- Space Complexity
- Big O notation

### Практика
Разобрать:
- O(1)
- O(log n)
- O(n)
- O(n log n)
- O(n²)

---

## Day 2 — Arrays & Sliding Window

### Практика
- 3 Easy
- 2 Medium

### Задачи
- Maximum Subarray
- Best Time to Buy and Sell Stock

---

## Day 3 — Hash Table (Map / Set)

### Задачи
- Two Sum
- Contains Duplicate
- Longest Substring Without Repeating Characters

---

## Day 4 — Two Pointers

### Задачи
- Remove Duplicates from Sorted Array
- 3Sum
- Container With Most Water

---

## Day 5 — Sliding Window (Advanced)

### Задачи
- Longest Repeating Character Replacement
- Minimum Window Substring

---

## Day 6 — Практикум

### Задание
Решить:
- 8–10 задач за день;
- разобрать все решения.

---

## Day 7 — Отдых / Контест

### Задание
- Weekly LeetCode Contest
или
- Virtual Contest

---

# Week 3–4 — Stack, Queue, Linked List, Binary Search

## Day 8 — Stack Basics

### Задачи
- Valid Parentheses
- Min Stack
- Evaluate Reverse Polish Notation

---

## Day 9 — Queue & Deque

### Задачи
- Sliding Window Maximum
- Design Circular Queue

---

## Day 10 — Linked List Basics

### Задачи
- Reverse Linked List
- Merge Two Sorted Lists

---

## Day 11 — Advanced Linked List

### Задачи
- Merge k Sorted Lists
- LRU Cache

---

## Day 12 — Binary Search

### Задачи
- Binary Search
- Search Insert Position
- Find Minimum in Rotated Sorted Array

---

## Day 13 — Практикум

### Задание
Решить:
- 10–12 задач;
- провести разбор решений.

---

## Day 14 — Отдых / Контест

### Задание
Тематический контест по Binary Search.

---

# Week 5–6 — Trees & Binary Search Trees

## Day 15 — Binary Tree Basics

### Темы
- DFS
- BFS

### Задачи
- Maximum Depth of Binary Tree
- Invert Binary Tree
- Binary Tree Level Order Traversal

---

## Day 16 — Tree Traversal

### Темы
- Preorder
- Inorder
- Postorder

### Задачи
- Serialize and Deserialize Binary Tree

---

## Day 17 — Binary Search Tree

### Задачи
- Validate BST
- Lowest Common Ancestor
- Kth Smallest Element in BST

---

## Day 18 — Heap / Priority Queue

### Задачи
- K Closest Points to Origin
- Merge k Sorted Lists

---

## Day 19 — Практикум

### Задание
Смешанные задачи по Trees.

---

## Day 20 — Практикум

### Задание
Решить 12 задач.

---

## Day 21 — Отдых / Контест

### Задание
Tree Contest.

---

# Week 7–8 — Graphs & BFS/DFS

## Day 22 — Graph Representation

### Темы
- Adjacency List
- Graph traversal

### Задачи
- Number of Islands
- Max Area of Island

---

## Day 23 — BFS

### Задачи
- Shortest Path in Binary Matrix
- Rotting Oranges

---

## Day 24 — DFS & Flood Fill

### Задачи
- Surrounded Regions
- Clone Graph

---

## Day 25 — Topological Sort

### Задачи
- Course Schedule I
- Course Schedule II

---

## Day 26 — Dijkstra & Union-Find (DSU)

### Задачи
- Network Delay Time
- Number of Provinces

---

## Day 27 — Практикум

### Задание
Решить 10–12 задач по графам.

---

## Day 28 — Отдых / Контест

### Задание
Graph Contest.

---

# Week 9–10 — Dynamic Programming

## Day 29 — 1D DP Basics

### Задачи
- Climbing Stairs
- House Robber
- Min Cost Climbing Stairs

---

## Day 30 — 2D DP / Grid

### Задачи
- Unique Paths
- Minimum Path Sum

---

## Day 31 — Knapsack Problems

### Темы
- 0/1 Knapsack
- Unbounded Knapsack

### Задачи
- Partition Equal Subset Sum
- Coin Change

---

## Day 32 — Longest Common Subsequence

### Задачи
- Longest Common Subsequence
- Edit Distance

---

## Day 33 — Практикум

### Задание
Классические задачи по DP.

---

## Day 34 — Практикум

### Задание
Решить 10 задач.

---

## Day 35 — Отдых / Контест

### Задание
DP Contest.

---

# Week 11–12 — Advanced Problems & Interview Prep

## Day 36 — Greedy Algorithms

### Задачи
- Jump Game
- Task Scheduler

---

## Day 37 — Bit Manipulation

### Задачи
- Single Number
- Missing Number

---

## Day 38–40 — Mixed Hard Problems

### Задание
Решать:
- Medium
- Hard

из Top 100 LeetCode.

---

## Day 41–42 — Mock Interviews

### Задание
Решать задачи:
- с таймером;
- по 45 минут;
- с объяснением решения вслух.

---

## Day 43–45 — Weak Topics Review

### Задание
- Повтор слабых тем
- Контесты
- Анализ ошибок

---

## Day 46–48 — Финальный Практикум

### Цель
Решить минимум:
```text
300 задач
```

---

# Финальный Чек-лист Track 2

- [ ] Решено 300+ задач на LeetCode
- [ ] Easy задачи решаются за 10–15 минут
- [ ] Medium задачи решаются за 25–35 минут
- [ ] Понимаю и могу объяснить основные структуры данных
- [ ] Понимаю базовое Dynamic Programming
- [ ] Готов к Junior/Middle technical interview

---

# Основные Темы Трека

## Structures
- Arrays
- Hash Tables
- Stack
- Queue
- Linked List
- Trees
- Graphs
- Heap
- Union-Find

## Algorithms
- Binary Search
- Sliding Window
- Two Pointers
- DFS/BFS
- Dynamic Programming
- Greedy
- Dijkstra
- Topological Sort



# Track 3 — Frontend Development (с нуля → высокий визуальный уровень)

**Длительность:** 16 недель (4 месяца)  
**Цель:**
- Начать frontend практически с нуля
- Освоить современные frontend-технологии
- Научиться создавать красивые интерфейсы и wow-эффекты
- Делать сложные анимации и 3D-сцены
- Подготовить сильное визуальное портфолио

**Формат:**  
6 дней обучения + 1 день полировки/отдыха

---

# Week 1–2 — HTML, CSS & JavaScript Basics

## Day 1 — HTML5 Семантика & Структура

### Темы
- Semantic HTML
- Layout structure
- Accessibility basics

---

## Day 2 — CSS Basics & Flexbox

### Темы
- Selectors
- Box model
- Flexbox layout

---

## Day 3 — CSS Grid & Responsive Design

### Темы
- CSS Grid
- Media Queries
- Responsive layouts

---

## Day 4 — CSS Animations & Transitions

### Темы
- Transitions
- Keyframes
- Hover animations

---

## Day 5 — JavaScript Basics

### Темы
- Variables
- Functions
- Arrays & Objects
- DOM basics

---

## Day 6 — Практикум

### Проект
Красивая личная страница:
- визитка;
- резюме;
- links page.

---

## Day 7 — Полировка

### Задание
- улучшить UI;
- адаптивность;
- анимации.

---

# Week 3–4 — Modern JavaScript & TypeScript

## Day 8 — ES6+

### Темы
- Arrow Functions
- Destructuring
- Modules
- Spread/Rest operators

---

## Day 9 — Async JavaScript

### Темы
- Async/Await
- Fetch API
- Promises

---

## Day 10 — TypeScript Basics

### Темы
- Types
- Interfaces
- Functions
- Arrays

---

## Day 11 — Advanced TypeScript

### Темы
- Generics
- Utility Types
- Advanced interfaces

---

## Day 12 — DOM & Events Deep Dive

### Темы
- Event listeners
- Event delegation
- Dynamic DOM updates

---

## Day 13 — Практикум

### Проект
Todo App на TypeScript.

---

## Day 14 — Отдых

---

# Week 5–7 — React + TypeScript

## Day 15 — React Basics & JSX

### Темы
- Components
- JSX
- Project structure

---

## Day 16 — State & Props

### Темы
- useState
- Props
- Component communication

---

## Day 17 — useEffect & Lifecycle

### Темы
- Side effects
- Data fetching
- Lifecycle logic

---

## Day 18 — React Router v6

### Практика
Создать:
- routes;
- nested routes;
- layouts.

---

## Day 19 — Custom Hooks

### Практика
Создать собственные hooks.

---

## Day 20–21 — Практикум

### Проект
Todo App:
- routing;
- filters;
- localStorage;
- красивый UI.

---

## Day 22–28 — Большой Проект

### Проект
Современное личное портфолио:
- animations;
- responsive design;
- dark mode;
- modern UI.

---

# Week 8–10 — Advanced Styling & Animations

## Day 29 — Tailwind CSS

### Темы
- Utility-first styling
- Responsive utilities
- Layout systems

---

## Day 30 — shadcn/ui + Radix

### Практика
Создать:
- dialogs;
- buttons;
- dropdowns;
- cards.

---

## Day 31 — Framer Motion Basics

### Темы
- Motion components
- Hover animations
- Transitions

---

## Day 32 — Framer Motion Advanced

### Темы
- Scroll animations
- Gestures
- Complex transitions

---

## Day 33 — GSAP + ScrollTrigger

### Практика
Создать:
- scroll effects;
- cinematic animations;
- timeline animations.

---

## Day 34–38 — Практикум

### Проект
AI Landing Page:
- wow animations;
- modern layout;
- motion effects;
- responsive design.

---

## Day 39–42 — Практикум

### Проект
3D Hero Section:
- React Three Fiber;
- interactive objects;
- camera animations.

---

# Week 11–13 — Next.js 15 + 3D Experiences

## Day 43 — Next.js 15 App Router

### Темы
- App Router
- Server Components
- Client Components

---

## Day 44 — Server Actions & Data Fetching

### Практика
- forms;
- server actions;
- optimized loading.

---

## Day 45 — React Three Fiber + Drei

### Темы
- 3D scenes
- Lights
- Materials
- Cameras

---

## Day 46 — Interactive 3D Animations

### Практика
Создать интерактивную 3D-сцену.

---

## Day 47 — Post-processing Effects

### Темы
- Bloom
- Depth of field
- Motion blur

---

## Day 48–52 — Большой Проект

### Проект
Интерактивное 3D Портфолио:
- animations;
- 3D scenes;
- cinematic effects;
- smooth UX.

---

## Day 53–56 — Второй Wow-Проект

### Идеи
- AI Experience;
- Futuristic Dashboard;
- Interactive Product Page;
- 3D AI Interface.

---

# Week 14–16 — Finalization & Portfolio

## Основные задачи

### Полировка
- animations;
- UX;
- performance;
- responsive fixes.

---

### Главный Portfolio Website

### Цели
- wow-effect;
- premium UI;
- motion design;
- personal branding.

---

### Deployment

### Платформа
- Vercel

---

### Documentation

### Задание
Подготовить:
- README;
- project cases;
- screenshots;
- demo videos.

---

# Финальный Чек-лист Track 3

- [ ] Уверенно владею TypeScript + React + Next.js 15
- [ ] Создаю современные адаптивные интерфейсы
- [ ] Использую Tailwind CSS + shadcn/ui
- [ ] Делаю сложные анимации на Framer Motion и GSAP
- [ ] Работаю с 3D в браузере через React Three Fiber
- [ ] Есть минимум 3–4 визуально сильных проекта
- [ ] Умею создавать wow-интерфейсы для клиентов и портфолио

---

# Основные Технологии

## Frontend
- HTML5
- CSS3
- JavaScript
- TypeScript
- React
- Next.js 15

## Styling & UI
- Tailwind CSS
- shadcn/ui
- Radix UI

## Animations
- Framer Motion
- GSAP
- ScrollTrigger

## 3D
- React Three Fiber
- Drei
- Post-processing

## Deployment
- Vercel


# Track 4 — Backend + ИИ Инженерия

**Длительность:** 14 недель (3.5 месяца)  
**Цель:**
- Стать сильным Fullstack AI-разработчиком
- Научиться строить production-ready backend
- Освоить современные AI-инструменты
- Создавать RAG, Agents и AI-системы

**Формат:**  
6 дней обучения + 1 день практики/рефакторинга

---

# Week 1–2 — Modern Backend Fundamentals (FastAPI)

## Day 1 — FastAPI + Pydantic v2

### Темы
- FastAPI basics
- Pydantic v2
- Request/Response validation

### Практика
Создать CRUD API с валидацией.

---

## Day 2 — Async SQLAlchemy 2.0 + Alembic

### Темы
- Async ORM
- Relationships
- Database migrations

### Практика
Настроить:
- PostgreSQL;
- модели;
- миграции.

---

## Day 3 — Dependency Injection + JWT

### Темы
- Dependency Injection
- JWT Authentication
- Authorization

### Практика
Полноценная система аутентификации.

---

## Day 4 — Error Handling & Logging

### Темы
- Global exceptions
- Structured logging
- Error responses

### Практика
Создать единую систему ошибок.

---

## Day 5 — Background Tasks + Celery + Redis

### Темы
- Async tasks
- Queue workers
- Redis integration

### Практика
Создать фоновые задачи.

---

## Day 6 — Практикум

### Проект
Переписать свой AI Support System на современный FastAPI.

---

## Day 7 — Полировка

### Задание
- cleanup;
- refactoring;
- API improvements.

---

# Week 3–4 — Advanced Backend

## Day 8 — Security & Middleware

### Темы
- Rate Limiting
- CORS
- Security Headers

### Практика
Настроить middleware и защиту API.

---

## Day 9 — WebSockets + SSE

### Темы
- Real-time updates
- Streaming responses

### Практика
Реализовать realtime-функциональность.

---

## Day 10 — Testing

### Инструменты
- pytest
- async testing

### Практика
Покрытие ключевых модулей тестами (80%+).

---

## Day 11 — Docker & Docker Compose

### Практика
Собрать multi-service stack:
- FastAPI;
- PostgreSQL;
- Redis;
- Celery.

---

## Day 12 — CI/CD Basics

### Инструменты
- GitHub Actions
- Linters
- Auto testing

### Практика
Настроить pipeline.

---

## Day 13 — Практикум

### Проект
Улучшенная версия:
- ProfBot;
или
- AI Task Assistant.

---

## Day 14 — Отдых

---

# Week 5–7 — AI Engineering (LangChain & RAG)

## Day 15 — LangChain Basics

### Темы
- Chains
- Prompts
- Memory

---

## Day 16 — Advanced Prompts & Output Parsers

### Практика
Structured output и parsing.

---

## Day 17 — RAG Fundamentals

### Темы
- Retrieval-Augmented Generation
- Vector Databases

### Инструменты
- FAISS
- Chroma

---

## Day 18 — Embeddings & Semantic Search

### Темы
- Embeddings
- Similarity Search

### Инструменты
- Sentence Transformers

---

## Day 19 — Agents & Tools

### Практика
Создать AI-агента с инструментами.

---

## Day 20 — LangGraph

### Темы
- Stateful agents
- Multi-step workflows

---

## Day 21 — Практикум

### Проект
Персональный AI-ассистент:
- память;
- RAG;
- history;
- tools.

---

## Day 22–28 — Большой Проект

### Проект
AI Knowledge Base:
- загрузка PDF;
- загрузка конспектов;
- semantic search;
- AI chat.

---

# Week 8–9 — Advanced AI Systems

## Day 29 — Multi-Agent Systems

### Практика
Создать нескольких AI-агентов с разными ролями.

---

## Day 30 — Evaluation & Monitoring

### Темы
- LangSmith
- AI metrics
- tracing

---

## Day 31 — Function Calling & Tools

### Практика
Интеграция:
- внешних API;
- tools;
- automation.

---

## Day 32 — Long-Term Memory

### Темы
- Vector Store
- Summary Memory
- Persistent memory

---

## Day 33 — Production Readiness

### Темы
- rate limits;
- caching;
- retries;
- fallback models.

---

## Day 34–35 — Практикум

### Проект
Улучшенный AI Support System на LangGraph.

---

## Day 36 — Отдых

---

# Week 10–12 — AI Fullstack Projects

## Day 37–42 — Project 1: Smart AI Assistant

### Цели
- RAG;
- Agents;
- Memory;
- Tool usage;
- chat interface.

---

## Day 43–48 — Project 2: AI Task Manager / Helpdesk

### Цели
- сложная бизнес-логика;
- AI automation;
- fullstack architecture;
- realtime updates.

---

## Day 49–52 — Project 3 (Optional)

### Идеи
- AI Code Assistant
- CV Analyzer
- AI Study Assistant
- AI Notes System

---

## Day 53–56 — Documentation & Polish

### Задание
Подготовить:
- README;
- screenshots;
- architecture diagrams;
- demo videos.

---

# Week 13–14 — Freelance & Production Preparation

## Основные задачи

### Deployment
- Railway
- Render
- VPS deployment

### Optimization
- performance;
- database optimization;
- caching.

### Portfolio
Создать сильное AI portfolio.

### Freelance
Подготовить:
- предложения клиентам;
- project showcase;
- pricing structure.

---

# Финальный Чек-лист Track 4

- [ ] Уверенно строю production-ready FastAPI backend
- [ ] Понимаю async backend architecture
- [ ] Глубоко понимаю LangChain и LangGraph
- [ ] Умею строить качественные RAG-системы
- [ ] Использую embeddings и vector databases
- [ ] Есть минимум 3 AI Fullstack проекта
- [ ] Умею деплоить production AI apps
- [ ] Готов брать AI/backend заказы на фрилансе

---

# Основные Технологии

## Backend
- FastAPI
- SQLAlchemy 2.0
- PostgreSQL
- Redis
- Celery

## AI Engineering
- LangChain
- LangGraph
- RAG
- Agents
- Embeddings

## Vector Databases
- FAISS
- Chroma

## Infrastructure
- Docker
- Docker Compose
- GitHub Actions
- Railway
- Render

## AI Features
- Semantic Search
- Function Calling
- Memory Systems
- Multi-Agent Workflows




