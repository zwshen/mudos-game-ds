//updated 27/12
inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("�x�߹p�u��",({"bullet clip","bullet","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long","�@�Ӫ��ݻs���u��, �C�@�ռu���X�t�ɳ��˦�5�o�l�u�C\n");
        }
    set("value", 300);
  set_weight(500);
set("amount",5);		//�u�Ķq
  set("bullet/damage",10);   //���ˤO
set("bullet/unit","�o");	//�u�ĳ��
set("bullet/name","�l�u");	//�u�ĦW��
set("type","small");		//�l�u����
setup();
}
