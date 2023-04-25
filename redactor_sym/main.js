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

tinymce.init({
    selector: "#bodyRedactor",
    // theme: "modern",
    // width: 680,
    height: 600,
    // relative_urls: false,
    // remove_script_host: false,
    // document_base_url: BASE_URL,
    plugins: "advlist autolink link image lists charmap print preview hr anchor pagebreak searchreplace wordcount visualblocks visualchars insertdatetime media nonbreaking table contextmenu directionality emoticons paste textcolor code",
    toolbar1: "undo redo | bold italic underline | alignleft aligncenter alignright alignjustify | bullist numlist outdent indent | styleselect",
    toolbar2: " | link unlink anchor | image media | forecolor backcolor  | print preview code ",
    image_advtab: true,

    language: "ru",
    // valid_elements: 'a, div, p, span, img, script, style, h1, h2, h3, h4, h5, h6',
    extended_valid_elements: "img[*],style[*],list[*],p[*],span[*],table[*],tbody[*],tr[*],td[*]",
    // extended_valid_elements: "style[*]",
});


let ID_REDACTOR = "bodyRedactor";

function Test_aa() {
    let el_parent = document.querySelector('#'+ID_REDACTOR+'_ifr').contentWindow.document.body;
    alert(el_parent.innerHTML)
}
  
setTimeout(Test_aa, 5000);

