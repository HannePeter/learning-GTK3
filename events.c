#include <stdlib.h>
#include <gtk/gtk.h>
#include "main_window.h"
#include "events_cb.h"



int main(int argc, char **argv)
{
    GtkWidget *win, *label;

    gtk_init(&argc, &argv);

    win = create_window("Events", 300, 200);
    label = g_object_new(GTK_TYPE_LABEL, NULL);

    g_signal_connect(win, "enter-notify-event", G_CALLBACK(change_label1), label);
    g_signal_connect(win, "leave-notify-event", G_CALLBACK(change_label2), label);
    g_signal_connect(win, "button-press-event", G_CALLBACK(show_pos), label);
    g_signal_connect(win, "key-press-event", G_CALLBACK(key_press), label);
    gtk_widget_set_events(win, GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK
                                 | GDK_ENTER_NOTIFY_MASK | GDK_LEAVE_NOTIFY_MASK
                                 | GDK_KEY_PRESS_MASK);

    gtk_container_add(GTK_CONTAINER(win), label);
 
    gtk_widget_show_all(GTK_WIDGET(win));
    gtk_main();

    g_print("Die GTK-Hauptschleife wurde beendet!\n");
    return EXIT_SUCCESS;
}

