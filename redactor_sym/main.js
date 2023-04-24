// создание "джейсон структуры, с инфой"
let text = JSON.stringify({hello:'example'});
// вызов функции, которая создаст и скачает на комп клиента файл
downloadAsFile(text);

// Функция автоматической загрузки файла
function downloadAsFile(data) {
    // к какому элементу 
    let a = document.querySelector("a");
    // Создаем файл
    let file = new Blob([data], {type: 'application/json'});
    // Привязываем к ссылке, или вшиваем в ссылку, объект "файл"
    a.href = URL.createObjectURL(file);
    // название файла
    a.download = "example.txt";
    // кликаем программно по ссылке, для автоматической загрузки
    // a.click();
}
