#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name("[1;37m  £S [1;33m¦Ì¦Ìº¸¥Û¸O [1;37m£S [0m",({"mimir board","board"}));
  set("long",
"
      "HIC"¤@¶ô¥Ñ"HIG"©_²§¥ú¥Û"HIC"³y¦¨ªº¥Û¸OÁq¥ß¦b³o¸Ì¡A
  "HIC"©_©Çªº¬O¡A¥Û¸Oªí­±³ºµM¤£Â_¯B²{©_¯Sªº"HIW"¥úªö"HIY"¦¥¤å(rune)
    "HIC"§A©w²´¤@¬Ý¡A³o"HIY"¦¥¤å"HIC"³º¦ÛµMÂà´«¦¨§A¼ô±xªº¤å¦r!!?"NOR"

" );

set("location","/u/s/saint/workroom.c");

 set("board_id","saint_b");
setup();
  set("capacity",100);

}
