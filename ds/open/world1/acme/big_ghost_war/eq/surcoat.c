/* eq write by -Acme-
*/

#include <ansi2.h>
#include <armor.h>

inherit SURCOAT;
void create()
{
    switch( random(100) ) {
        case 0..20:
            set_name(HBK"�}���ܪ�"NOR ,({ "po god surcoat", "surcoat" }) );
            set("long","�@��Ӧ۰��ɪ��ܪӡA�Ǧ⪺�����t�ơC\n");
            set_weight(7000);
            set("value", random(5000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(6)+14);
            break;
        case 21..45:
            set_name(HBK"�x�ߩܪ�"NOR ,({ "heart surcoat", "surcoat" }) );
            set("long","�@��������H�����ܪӡC\n");
            set_weight(6000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(6)+10);
            break;
        case 46..70:
            set_name(HBK"�k��ܪ�"NOR ,({ "west surcoat", "surcoat" }) );
            set("long","�@��Ωǲ�����s�����������C\n");
            set_weight(2000);
            set("value", random(4000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(6)+6);
            break;
        default:
            set_name(HBK"�Ի�ܪ�"NOR ,({ "ghost surcoat", "surcoat" }) );
            set("long","�@��Ӧۧ��ɪ��ܪӡA���G�s�۳\\�h���F�C\n");
            set_weight(4000);
            set("value", random(3000)+1 );
            set("volume", 5);
            set("armor_prop/armor", random(6)+3);
            break;
    }

    switch( random(100) ) {
        case 0..19: set("armor_prop/str",1); break;
        case 20..39: set("armor_prop/con",1); break;
        case 40..59: set("armor_prop/int",1); break;
        case 60..79: set("armor_prop/dex",1); break;
        case 99:
            set("armor_prop/str", 1);
            set("armor_prop/con", 1);
            set("armor_prop/int", 1);
            set("armor_prop/dex", 1);
            break;
    }

    if ( clonep() )
        set_default_object(__FILE__);
    else {
        set("material", "iron");
        set("unit", "��" );
    }

    setup();
}