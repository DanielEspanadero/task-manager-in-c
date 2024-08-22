![image](https://github.com/DanielEspanadero/task-manager-in-c/blob/master/docs/task-manager.png)

## Descripción

Este Administrador de Tareas es una aplicación en C diseñada para gestionar una lista de tareas usando una lista enlazada. Los usuarios pueden realizar varias operaciones como agregar, visualizar, marcar como completadas y eliminar tareas. La aplicación también soporta la persistencia de datos mediante el guardado y la carga de tareas desde un archivo.

## Funcionalidades

1. **Agregar Tarea**: Permite al usuario ingresar una nueva tarea con los siguientes detalles:
    - Nombre
    - Prioridad (un valor entre 1 y 5)
    - Fecha límite (formato YYYY-MM-DD)
    - Descripción

2. **Mostrar Tareas**: Muestra todas las tareas presentes en la lista, incluyendo sus detalles.

3. **Marcar Tarea como Completada**: Permite al usuario marcar una tarea como completada. La búsqueda se realiza por nombre de la tarea.

4. **Eliminar Tarea**: Elimina una tarea específica de la lista por nombre.

5. **Salir**: Guarda las tareas en el archivo y sale de la aplicación.

## Estructura del Proyecto

El proyecto está organizado en varios archivos para una mejor modularidad y mantenimiento:

- **`include/`**: Carpeta que contiene los archivos de encabezado (`.h`).
- **`src/`**: Carpeta que contiene los archivos fuente (`.c`).

### Archivos y Funciones

#### `include/task.h`

Define la estructura `Task` y las declaraciones de funciones relacionadas con las tareas:

- **`Task`**: Estructura que representa una tarea con atributos como nombre, prioridad, fecha límite, descripción, y estado de completado.
- Funciones:
    - `Task* createTask(char name[], int priority, char deadline[], char description[])`
    - `void printTask(Task *task)`
    - `void markTaskAsCompleted(Task *task)`
    - `int isValidDate(char *date)`
    - `int isFutureDate(char *date)`

#### `include/list.h`

Declara las funciones para manipular la lista de tareas:

- Funciones:
    - `Node* addTask(Node *list, Task *newTask)`
    - `Task* findTask(Node *list, char name[]);`
    - `Node* removeTask(Node *list, char name[])`
    - `void displayTasks(Node *list)`

#### `include/file.h`

Declara las funciones para guardar y cargar tareas desde un archivo:

- Funciones:
    - `void saveTasksToFile(const char *filename, Node *taskList)`
    - `Node* loadTasksFromFile(const char *filename)`

#### `src/task.c`

Implementa las funciones relacionadas con las tareas, incluyendo la creación, impresión, marcado como completada y validación de fechas.

#### `src/list.c`

Implementa las funciones para manejar la lista de tareas, como agregar, buscar, eliminar y mostrar tareas.

#### `src/file.c`

Implementa las funciones para guardar y cargar tareas desde un archivo.

#### `src/main.c`

Contiene la lógica principal de la aplicación y la interfaz del usuario. Maneja la visualización del menú, la recepción de entradas del usuario y llama a las funciones correspondientes para realizar las operaciones solicitadas.

## Compilación y Ejecución

Para compilar y ejecutar el proyecto, sigue estos pasos:

1. **Compilación**: Usa un compilador de C para compilar los archivos fuente. Por ejemplo, usando `gcc`:

    ```sh
   make
    ```

   Esto compila todos los archivos en `src/` y genera un ejecutable llamado `task_manager`.

2. **Ejecución**: Ejecuta el archivo compilado:

    ```sh
    ./task_manager
    ```

3. **Archivos de Entrada/Salida**:
    - **Entrada**: La aplicación solicita datos al usuario a través de la consola.
    - **Salida**: Las tareas se guardan en un archivo llamado `tasks.txt` (o cualquier otro especificado) para su persistencia.

## Validaciones

El proyecto incluye validaciones para asegurar que:

- Los nombres de las tareas sean únicos.
- Las fechas ingresadas sean válidas y estén en el futuro.
- La prioridad esté en el rango de 1 a 5.

## Notas Adicionales

- **Colores en la Consola**: Se utilizan códigos ANSI para mejorar la visualización en la consola.
- **Manejo de Errores**: Se incluye manejo básico de errores para operaciones de archivo y asignación de memoria.
