#include <ansi.h>
inherit ITEM;

string *attr1 = ({"¤ì","¤õ","¤g","ª÷","¤ô"});
string *attr2 = ({"°®","©[","¾_","´S","Â÷","§I","§¢","¦á"});
string *attr3 = ({"¤s","¤ô","¿A","¤õ","­·","¹p","¦a","¤Ñ"});
string *g_name= ({"wood","fire","mud","gold","water"});
int *value = ({ 9,8,7,6,4,3,2,1 });

void create()
{
        set_name("ªü´ú", ({ "ar test","test"}) );
        set("long","Test\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(100);
                set("unit", "¤Y");
        }
        setup();
}

void init()
{
        add_action("do_drug","drug");
}
int do_drug(string arg)
{
        int i;
        string name="";
        object drug;

        i=sizeof(attr1);
        while( i-- )
        {
                drug=new(__DIR__"drug.c");

                drug->set("attr1",i+1);

                name+=attr1[i];
                switch( random(8) )
                {
                                case 0:
                                        drug->set("attr2",value[0]);
                                        drug->set("attr3",value[7]);
                                        name+=attr2[0];
                                        name+=attr3[7];
                                        drug->set_name("ÃÄ§÷-"+name , ({ g_name[i]+" drug","drug"}) );
                                        break;
                                case 1:
                                        drug->set("attr2",value[1]);
                                        drug->set("attr3",value[6]);
                                        name+=attr2[1];
                                        name+=attr3[6];
                                        drug->set_name("ÃÄ§÷-"+name , ({ g_name[i]+" drug","drug"}) );
                                        break;
                                case 2:
                                        drug->set("attr2",value[2]);
                                        drug->set("attr3",value[5]);
                                        name+=attr2[2];
                                        name+=attr3[5];
                                        drug->set_name("ÃÄ§÷-"+name , ({ g_name[i]+" drug","drug"}) );
                                        break;
                                case 3:
                                        drug->set("attr2",value[3]);
                                        drug->set("attr3",value[4]);
                                        name+=attr2[3];
                                        name+=attr3[4];
                                        drug->set_name("ÃÄ§÷-"+name , ({ g_name[i]+" drug","drug"}) );
                                        break;
                                case 4:
                                        drug->set("attr2",value[4]);
                                        drug->set("attr3",value[3]);
                                        name+=attr2[4];
                                        name+=attr3[3];
                                        drug->set_name("ÃÄ§÷-"+name , ({ g_name[i]+" drug","drug"}) );
                                        break;
                                case 5:
                                        drug->set("attr2",value[5]);
                                        drug->set("attr3",value[2]);
                                        name+=attr2[5];
                                        name+=attr3[2];
                                        drug->set_name("ÃÄ§÷-"+name , ({ g_name[i]+" drug","drug"}) );
                                        break;
                                case 6:
                                        drug->set("attr2",value[6]);
                                        drug->set("attr3",value[1]);
                                        name+=attr2[6];
                                        name+=attr3[1];
                                        drug->set_name("ÃÄ§÷-"+name , ({ g_name[i]+" drug","drug"}) );
                                        break;
                                case 7:
                                        drug->set("attr2",value[7]);
                                        drug->set("attr3",value[0]);
                                        name+=attr2[7];
                                        name+=attr3[0];
                                        drug->set_name("ÃÄ§÷-"+name , ({ g_name[i]+" drug","drug"}) );
                                        break;
                }
                name="";
                drug->move(environment(this_object()));
        }

        return 1;
}
