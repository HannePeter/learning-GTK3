#include <stdio.h>
#include <gtk/gtk.h>

#define BUTTONS 4

extern GtkWidget *buttons[BUTTONS], *t_buttons[BUTTONS], *r_buttons[BUTTONS], *c_buttons[BUTTONS];



////////////////////////////////////////////////////////////// toogled_auswerten
void toogled_auswerten(GtkWidget *widget, gpointer data)
{
    gboolean toggled[BUTTONS] = {FALSE};

    puts("Toggled-Button Auswertung:");
    for (int i = 0; i < BUTTONS; i++)
    {
        g_object_get(t_buttons[i], "active", toggled+i, NULL);
        if (toggled[i])
            printf("Toggled-Button %d ist aktiviert\n", i+1);
    }
    puts("--------------------------------");
}

////////////////////////////////////////////////////////////// radio_auswerten
void radio_auswerten(GtkWidget *widget, gpointer data)
{
    gboolean radio[BUTTONS] = {FALSE};

    puts("Radio-Button Auswertung:");
    for (int i = 0; i < BUTTONS; i++)
    {
        g_object_get(r_buttons[i], "active", radio+i, NULL);
        if (radio[i])
            printf("Radio-Button %d ist aktiviert\n", i+1);
    }
    puts("--------------------------------");
}

////////////////////////////////////////////////////////////// check_auswerten
void check_auswerten(GtkWidget *widget, gpointer data)
{
    gboolean check[BUTTONS] = {FALSE};

    puts("Check-Button Auswertung:");
    for (int i = 0; i < BUTTONS; i++)
    {
        g_object_get(c_buttons[i], "active", check+i, NULL);
        if (check[i])
            printf("Check-Button %d ist aktiviert\n", i+1);
    }
    puts("--------------------------------");
}

