#include <stdio.h>
#include <gtk/gtk.h>



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// show_pos
void show_pos(GtkWidget *widget, GdkEventButton *event, GtkWidget *label)
{
    const char *button[] = {NULL, "linker Button", "mittlerer Button","rechter Button"};
    int x = event->x;
    int y = event->y;
    int pressed = event->button;
    char pos[100];
    sprintf(pos, "Event: %d, %d (%s)\n", x, y, button[pressed]);
    gtk_label_set_text(GTK_LABEL(label), pos);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// change_label1
void change_label1(GtkWidget *widget, GdkEventButton *event, GtkWidget *label)
{
    const char *new_label = "Event : Mauscursor tritt ins Fenster ein\n";
    gtk_label_set_text(GTK_LABEL(label), new_label);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// change_label2
void change_label2(GtkWidget *widget, GdkEventButton *event, GtkWidget *label)
{
    const char *new_label = "Event : Mauscursor hat Fenster verlassen\n";
    gtk_label_set_text(GTK_LABEL(label), new_label);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// key_press
void key_press(GtkWidget *widget, GdkEventKey *event, GtkWidget *label)
{
    char new_label[100];
    sprintf(new_label, "Event : Taste '%s' (Wert:%d) wurde gedrueckt\n", event->string, event->keyval);
    gtk_label_set_text(GTK_LABEL(label), new_label);
}

