#include <iostream>
#include <stdlib.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#define MAIN_UI_FILE "main_form.glade"
#define OPT_UI_FILE  "options_form.glade"

// описание виджетов
GtkBuilder *builder;
GtkWidget *topWindow;
GtkWidget *OptionsWindow;

// описание обработчиков сигналов
extern "C" void topWindow_destroy_cb (GtkWidget *object, gpointer user_data);
extern "C" void LeftButton_cl (GtkWidget *object);
extern "C" void RightButton_cl (GtkWidget *object);
extern "C" void UpButton_cl (GtkWidget *object);
extern "C" void DownButton_cl (GtkWidget *object);
extern "C" void OkButton_cl (GtkWidget *object);
extern "C" void BackButton_cl (GtkWidget *object);
extern "C" void HomeButton_cl (GtkWidget *object);
extern "C" void InfoButton_cl (GtkWidget *object);
extern "C" void MenuButton_cl (GtkWidget *object);
extern "C" void ZoomOutButton_cl (GtkWidget *object);
extern "C" void ZoomInButton_cl (GtkWidget *object);
extern "C" void VolDownButton_cl (GtkWidget *object);
extern "C" void MuteButton_cl (GtkWidget *object);
extern "C" void VolUpBotton_cl (GtkWidget *object);
extern "C" void PauseBotton_cl (GtkWidget *object);
extern "C" void PrevButton_cl (GtkWidget *object);
extern "C" void NextButton_cl (GtkWidget *object);
extern "C" void StopButton_cl (GtkWidget *object);
extern "C" void info_button_cl (GtkWidget *object);

extern "C" int options_button_cl (GtkWidget *object);


int main( int argc, char **argv )
{
    GError *error = NULL;

    // инициализация GTK+ 
    gtk_init( &argc, &argv );

   // создание нового GtkBuilder объекта
    builder = gtk_builder_new();

    // загрузка пользовательского интерфеса из файла, который мы создали в Glade 
    if( ! gtk_builder_add_from_file( builder, MAIN_UI_FILE, &error ) )
    {
        g_warning( "%s", error->message );
        g_free( error );
        return( 1 );
    }
  
   // связывание наших виджетов с описаннимем виджетов в GladeXML
   topWindow = GTK_WIDGET(gtk_builder_get_object(builder, "topWindow"));

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

void LeftButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Left\"");
}

void RightButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Right\"");
}

void UpButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Up\"");
}

void DownButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Down\"");
}

void OkButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Select\"");
}

void BackButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Back\"");
}

void HomeButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"XBMC.ActivateWindow(Home)\"");
}

void InfoButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Info\"");
}

void MenuButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"ContextMenu\"");
}

void ZoomOutButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"ZoomOut\"");
}

void ZoomInButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"ZoomIn\"");
}

void VolDownButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"VolumeDown\"");
}

void MuteButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Mute\"");
}

void VolUpBotton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"VolumeUp\"");
}

void PauseBotton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Pause\"");
}

void PrevButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"SkipPrevious\"");
}

void NextButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"SkipNext\"");
}

void StopButton_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Stop\"");
}

void info_button_cl (GtkWidget *object)
{
   system ("xbmc-send --host=\"192.168.1.5\" --action=\"Info\"");
}

int options_button_cl (GtkWidget *object)
{
   GError *error = NULL;

   // создание нового GtkBuilder объекта
   builder = gtk_builder_new();

    // загрузка пользовательского интерфеса из файла, который мы создали в Glade 
    if( ! gtk_builder_add_from_file( builder, OPT_UI_FILE, &error ) )
    {
        g_warning( "%s", error->message );
        g_free( error );
        return( 1 );
    }
  
   // связывание наших виджетов с описаннимем виджетов в GladeXML
   OptionsWindow = GTK_WIDGET(gtk_builder_get_object(builder, "OptionsWindow"));

   // связываем сигналы с объектами графического интерфейса
   gtk_builder_connect_signals (builder, NULL);

   // освобождение памяти
   g_object_unref( G_OBJECT( builder ) );
   
   // Показываем форму и виджеты на ней
   gtk_widget_show( OptionsWindow ); 
    
   // запуск главного цикла приложения
   gtk_main();

   return( 0 );

}
