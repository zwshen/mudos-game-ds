#include <weapon.h>

inherit FIST;

void create()
{
    set_name("指虎",({"tiger fist","fist"}) );
   set("long","一個套在手上的套件，一節一節的指環可讓四肢指頭套進去，雖然\n"
              "不像其他武器般的具有殺傷力，不過也不錯了。\n");
        set_weight(2000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","個");
            set("value",600);
        set("material","iron");
      init_fist(30);
   }
setup();
}

