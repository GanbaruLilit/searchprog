#include "Pageloader.h"

#include <curl/curl.h>

#include <errno.h>
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * getData это функция, которую вызывает библиотека curl
 * первым аргументом даёт input строку(то есть он прочёл)
 * Чтобы мы имели возможность эти данные хранить
 * нам дают возможность передать этой функции какой-то
 * аргумент для аутпута
 */
size_t getData(char* buffer, size_t itemSize, size_t itemCount, void* dest)
{
    size_t bytes = itemSize * itemCount;
    std::string* str = [std::string*]dest;
    str->assign(buffer, bytes);
    return bytes;
}
/**
 * mer pageloadery stanalua url-y
 * u heta talu infon et ssilkayov
 * statusi het miasin
 * u et amen inchy mer mot pahvelua
 * vspomogatelni Loadresult class-i mej 
 */

/** 
 * pageloader - для того чтобы получать исходный
 * код любой страницы на которой будем ссылаться
 */
Loadresult Pageloader::load(const std::string& url)
{
    //initialize CURL
    CURL* curl = curl_easy_init(); //библиотеку инициализируем

    /**
     * если мы собираемся загружать документ нам нужна
     * ссылка на объект curl, которая инициализируется
     * с помощью curl_easy_init()
     * Пото проверяем есть ли ошибка во время инициализации
     */
    /**
     * в строчке CURL* curl = curl_easy_init(); мы инициализируем
     * указатель на библиотеку curl
     */ 
    if(!curl)
    {
        perror("Init failed");
        exit(-1);
    }

    std::string contents

    //set options
    curl_easy_setup(curl, CURLOPT_URL, url.c_str());
    curl_easy_setup(curl, CURLOPT_WRITEFUNCTION, getData);
    curl_easy_setup(curl, CURLOPT_WRITEDATA, (void*)(&contents));

    /**
     * В строчках  curl_easy_setup... задаём опции CURL-у
     * 1)curl_easy_setup(curl, CURLOPT_URL, url.c_str());
     *   устанавливаем url откудо будем скачивать
     *   данные, то есть с помощю этого объекта curl
     *   ты должен скачивать из url такого-то
     * 2)что делает библотека curl?
     *   она говорит, что когда я прочту данные я передам
     *   её функции которую ты укажешь
     *   для этого на curl_easy_setup(curl, CURLOPT_WRITEFUNCTION, getData);
     *   мы указали функцию куда должна передать библиотека curl 
     *   те данные которые скачает
     * 3)но нам нужно куда-то записсать эти данные из 2)
     *   а не просто получить и всё, потому что 
     *   в самом конце мы должмны вернуть то что прочли
     *   return LoadResult(contents, curlinfoResponseCode);
     * ВКРАТЦЕ
     * 1)Скачай данные из этого url
     * 2)Когда ты скачаешь в какой то буфер вызови 
     *   функцию getData
     * 3)Передай функции getData как 4-ый аргумен то что 
     *   мы записали в curl_easy_setup(curl, CURLOPT_WRITEDATA, (void*)(&contents));
     */
    //connect to the url and download its' content
  

    CURLcode result = curl_easy_perform(curl);
    /**
     * CURLcode result = curl_easy_perform(curl);
     * это уже вызов операции, тат-как до этого мы подгатавливали 
     * операцию
     * когда мы вызываем эту операцию мы гарантированно знаем что если 
     * всё пройдёт нормально или по другому вызывится функция
     * getData в результате в переменной contents будет
     * конечный стринг
     */
    if(result != CURLE_OK)
    {
        perror("Download problem");
        exit(result);   
    }

    long curlinfoResponseCode;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &curlinfoResponseCode);

    curl_easy_cleanup(curl);
    return LoadResult(contents, curlinfoResponseCode);
}