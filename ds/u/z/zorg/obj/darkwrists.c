#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(HIW"�i"HIG"��"HIR"��"HIC"�@��"HIW"�j"NOR,({ "darkwrists","wrists" }) );
        set("long",""HIW"�i"HIG"��"HIR"��"HIC"�@��"HIW"�j"NOR"�W�x�z��"BLK"�`�¦�"NOR"�x����C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(700);
        set("material", "wrists");
        set("unit", "��" );
        set("no_sell",1);
        set("value",300);
        }
         set("armor_prop/armor", 150);
         set("armor_prop/parry", 200);
         set("armor_prop/shield", 150);
         set("armor_prop/dodge", 136);
         set("armor_prop/dex", 10);
         set("armor_prop/str", 10);
         set("armor_prop/con", 15);
         set("armor_prop/int", 5);
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
int query_autoload() { return 1; }
