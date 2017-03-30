#include <iostream>
#include <stdlib.h>
#include "domain.h"
#include "repository.h"
#include "controller.h"
#include "UI.h"
#include "testing.h"
using namespace std;



int main() {

	tests();



	

	Coat a( 33, "blue", 65, 3, "https://s-media-cache-ak0.pinimg.com/736x/00/4e/7b/004e7b590432e8a49b260141756785fe.jpg");
	Coat b{ 33, "red", 190, 2, "http://wardrobelooks.com/wp-content/uploads/2014/01/red-coats-for-women-1.jpg" };
	Coat c{ 34, "yellow",100, 1, "https://s-media-cache-ak0.pinimg.com/564x/50/19/53/501953610c6c185409765401e7f43465.jpg" };
	Coat d{ 33, "green", 89, 2, "http://www.justwomenfashion.com/wp-content/uploads/2016/04/new-winter-long-coat-women-double-breasted-fashion-woman-wool-green-coats-spain-ukraine-manteau.jpg" };
	Coat e{ 34, "pink", 59, 3, "https://s-media-cache-ak0.pinimg.com/originals/81/53/02/815302195da2d512ceaa56aea81faa1d.jpg" };
	Coat f( 35, "blue", 65, 2, "https://cdn.lookastic.com/looks/coat-turtleneck-skinny-pants-large-8093.jpg");
	Coat g{ 35, "red", 110, 1, "http://assets.myntassets.com/assets/images/1685683/2016/12/17/11481973153412-Athena-Women-Coats-4281481973153174-1.jpg" };
	Coat k{ 35, "yellow",39, 1, "https://ae01.alicdn.com/kf/HTB1efAVNVXXXXcHXXXXq6xXFXXXe/Hot-Sales-Winter-woolen-font-b-Coat-b-font-font-b-Women-b-font-Long-Loose.jpg" };
	Coat l{ 36, "green", 50, 1, "http://cdn2.next.co.uk/common/Items/Default/Default/Publications/GO5/shotview-315x472/2006/436-568s.jpg" };
	Coat m{ 36, "pink", 125, 2, "http://nord.imgix.net/Zoom/1/_10758821.jpg" };
    
	Repository repo;
	Controller ctrl(repo);

	ctrl.add_repo(a);
	ctrl.add_repo(b);
	ctrl.add_repo(c);
	ctrl.add_repo(d);
	ctrl.add_repo(e);
	ctrl.add_repo(f);
	ctrl.add_repo(g);
	ctrl.add_repo(k);
	ctrl.add_repo(l);
	ctrl.add_repo(m);

	UI ui(ctrl);
	ui.run();

	
	system("pause");
	return 0;

}
