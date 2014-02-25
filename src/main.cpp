#include <iostream>
#include <stdlib.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#define UI_FILE "main_form.glade"

// описание виджетов
GtkBuilder *builder;
GtkWidget *topWindow;
GtkRadioButton *rbutRectangle, *rbutEllipse, *rbutTriangle;
GtkDrawingArea *drawingarea;

// описание обработчиков сигналов
extern "C" void topWindow_destroy_cb (GtkWidget *object, gpointer user_data);
extern "C" void left_button_cl (GtkWidget *object);
extern "C" void right_button_cl (GtkWidget *object);
extern "C" void up_button_cl (GtkWidget *object);
extern "C" void down_button_cl (GtkWidget *object);
extern "C" void ok_button_cl (GtkWidget *object);
extern "C" void back_button_cl (GtkWidget *object);
extern "C" void home_button_cl (GtkWidget *object);
extern "C" void info_button_cl (GtkWidget *object);
extern "C" void menu_button_cl (GtkWidget *object);



int main( int argc, char **argv )
{
    boost::property_tree::ptree pt;
    pt.put("host","192.168.1.5");
    boost::property_tree::json_parser::write_json("config.json",pt);

    GError *error = NULL;

    // инициализация GTK+ 
    gtk_init( &argc, &argv );

   // создание нового GtkBuilder объекта
    builder = gtk_builder_new();

    // загрузка пользовательского интерфеса из файла, который мы создали в Glade 
    if( ! gtk_builder_add_from_file( builder, UI_FILE, &error ) )
    {
        g_warning( "%s", error->message );
        g_free( error );
        return( 1 );
    }
  
   // связывание наших виджетов с описаннимем виджетов в GladeXML
   topWindow = GTK_WIDGET(gtk_builder_get_object(builder, "topWindow"));
   rbutRectangle = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "rbutRectangle"));
   rbutEllipse = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "rbutEllipse"));
   rbutTriangle = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "rbutTriangle"));
   drawingarea = GTK_DRAWING_AREA(gtk_builder_get_object(builder, "drawingarea"));

   // связываем сигналы с объектами графического интерфейса
   gtk_builder_connect_signals (builder, NULL);

   // освобождение памяти
   g_object_unref( G_OBJECT( builder ) );
   
   // Показываем форму и виджеты на ней
   gtk_widget_show( topWindow ); 
    
   // запуск главного цикла приложения
   gtk_main();

   return( 0 );
}

// закрытие приложения
void topWindow_destroy_cb (GtkWidget *object, gpointer user_data)
{
 // завершаем главный цикл приложения
   std::cout << "Exit button pressed\n";
   gtk_main_quit();
}

// нажатие на кнопки

void left_button_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Left\"");
}

void right_button_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Right\"");
}

void up_button_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Up\"");
}

void down_button_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Down\"");
}

void ok_button_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Select\"");
}

void back_button_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Back\"");
}

void home_button_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"XBMC.ActivateWindow(Home)\"");
}

void info_button_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Info\"");
}

void menu_button_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"ContextMenu\"");
}
