#include <stdio.h>

#define alumnos 5
#define progresos 3

// Función para obtener el promedio de calificaciones de un alumno durante el semestre
float promedio_alumno(int calificaciones[progresos])
{
    float promedio = 0.0;

    for (int i = 0; i < progresos; ++i)
    {
        promedio += calificaciones[i];
    }

    return promedio / progresos;
}

// Función para calcular la nota promedio del grupo para cada progreso
float promedio_grupo(int calificaciones[alumnos][progresos], int progreso)
{
    float promedio = 0.0;

    for (int i = 0; i < alumnos; ++i)
    {
        promedio += calificaciones[i][progreso];
    }

    return promedio / alumnos;
}

// Función para encontrar al alumno con el mayor promedio de calificación durante el semestre
int mejor_alumno(int calificaciones[alumnos][progresos])
{
    int mejor_Alumno = 0;
    float mejor_Promedio = promedio_alumno(calificaciones[0]);

    for (int i = 1; i < alumnos; ++i)
    {
        float promedio_Actual = promedio_alumno(calificaciones[i]);
        if (promedio_Actual > mejor_Promedio)
        {
            mejor_Promedio = promedio_Actual;
            mejor_Alumno = i;
        }
    }

    return mejor_Alumno;
}

int main()
{
    int calificaciones[alumnos][progresos];

    // Ingresa las calificaciones
    printf("Ingrese las calificaciones de los estudiantes\n");
    for (int i = 0; i < alumnos; ++i)
    {
        printf("Estudiante %d \n", i + 1);
        for (int j = 0; j < progresos; ++j)
        {
            printf("Progreso %d: ", j + 1);
            scanf("%d", &calificaciones[i][j]);
        }
    }

    // Calcula y muestra el promedio de calificaciones de cada alumno
    printf("\nPromedio de calificaciones de cada alumno:\n");
    for (int i = 0; i < alumnos; ++i)
    {
        printf("Estudiante %d: %.2f\n", i + 1, promedio_alumno(calificaciones[i]));
    }

    // Calcula y muestra la nota promedio del grupo para cada progreso
    printf("\nNota promedio del grupo para cada progreso:\n");
    for (int j = 0; j < progresos; ++j)
    {
        printf("Progreso %d: %.2f\n", j + 1, promedio_grupo(calificaciones, j));
    }

    // Encuentra y muestra al alumno con el mayor promedio de calificación durante el semestre
    int mejor_Alumno = mejor_alumno(calificaciones);
    printf("\nEl alumno con el mayor promedio es el Estudiante %d\n", mejor_Alumno + 1);

    return 0;
}
