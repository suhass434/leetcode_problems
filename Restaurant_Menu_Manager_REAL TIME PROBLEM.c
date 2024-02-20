#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct MenuItem {
char name[50];
float price;
struct MenuItem* next;
};
void displayMenu(struct MenuItem* head) {
printf("Menu:\n");
printf("------------------------------\n");
while (head != NULL) {
printf("%s - $%.2f\n", head->name, head->price);
head = head->next;
}
printf("------------------------------\n");
}
struct MenuItem* addItem(struct MenuItem* head, char name[], float price)
{
struct MenuItem* newItem = (struct MenuItem*)malloc(sizeof(struct
MenuItem));
if (newItem == NULL) {
printf("Error: Memory allocation failed.\n");
return head;
}
strncpy(newItem->name, name, sizeof(newItem->name));
newItem->price = price;
newItem->next = head;
printf("Item added: %s - $%.2f\n", newItem->name, newItem->price);
return newItem;
}
struct MenuItem* deleteItem(struct MenuItem* head, char name[]) {
struct MenuItem* current = head;
struct MenuItem* prev = NULL;
while (current != NULL && strcmp(current->name, name) != 0) {
prev = current;
current = current->next;
}
if (current == NULL) {
printf("Error: Item not found.\n");
return head;
}
if (prev == NULL) {
head = current->next;
} else {
prev->next = current->next;
}
printf("Item deleted: %s - $%.2f\n", current->name, current->price);
free(current);
return head;
}
void freeMenu(struct MenuItem* head) {
struct MenuItem* current = head;
while (current != NULL) {
struct MenuItem* next = current->next;
free(current);
current = next;
}
}
float calculateTotal(struct MenuItem* order) {
float total = 0.0;
while (order != NULL) {
total += order->price;
order = order->next;
}
return total;
}
int main() {
struct MenuItem* menu = NULL;
struct MenuItem* order = NULL;
menu = addItem(menu, "Burger", 5.99);
menu = addItem(menu, "Pizza", 8.49);
menu = addItem(menu, "Salad", 4.99);
displayMenu(menu);
order = addItem(order, "Burger", 5.99);
order = addItem(order, "Pizza", 8.49);
printf("\nOrder Summary:\n");
displayMenu(order);
float totalBill = calculateTotal(order);
printf("\nTotal Bill: $%.2f\n", totalBill);
// Cleaning up memory
freeMenu(menu);
freeMenu(order);
return 0;
}
