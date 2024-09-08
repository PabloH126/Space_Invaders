#include "../libraries/CoversManager.h"

CoversManager::CoversManager() {
	for (int i = 1; i <= 5; i++) {
		covers.emplace_back(i);
	}
}
