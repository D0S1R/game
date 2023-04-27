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

// tinymce.init({
//     selector: "#bodyRedactor",
//     // theme: "modern",
//     // width: 680,
//     height: 650,
//     // relative_urls: false,
//     // remove_script_host: false,
//     // document_base_url: BASE_URL,
//     plugins: "",//advlist autolink link image lists charmap print preview hr anchor pagebreak searchreplace wordcount visualblocks visualchars insertdatetime media nonbreaking table contextmenu directionality emoticons paste textcolor code",
//     toolbar1: "",//undo redo | bold italic underline | alignleft aligncenter alignright alignjustify | bullist numlist outdent indent | styleselect",
//     toolbar2: "",// | link unlink anchor | image media | forecolor backcolor  | print preview code ",
//     image_advtab: true,

//     language: "ru",
//     // valid_elements: 'a, div, p, span, img, script, style, h1, h2, h3, h4, h5, h6',
//     extended_valid_elements: "img[*],style[*],list[*],p[*],span[*],table[*],tbody[*],tr[*],td[*]",
//     // extended_valid_elements: "style[*]",
// });


// let ID_REDACTOR = "bodyRedactor";
// // TODO: настройка шрифта в редакторе
// function settings_red() {
//     let el_parent = document.querySelector('#'+ID_REDACTOR+'_ifr').contentWindow.document.body;
//     alert(el_parent.innerHTML)
//     el_parent.style.fontSize = "10px";
//     el_parent.style.fontFamily = "Lucida Console";

//     let el_head_in_frayme = document.querySelector('#'+ID_REDACTOR+'_ifr').contentWindow.document.querySelector("head");
//     let link_style = document.createElement("link");
//     link_style.rel = "stylesheet"
//     link_style.href = "style.css"
//     el_head_in_frayme.append(link_style);
// }
  
// setTimeout(settings_red, 1000);

// ИЗМЕНЕНИЕ ЦВЕТА
let btn_colorMap = document.querySelector("#colorMap");

btn_colorMap.onclick = () => {
    let el_table = document.querySelector("#editColorMap");
    el_table.style.borderSpacing = "0px";
    el_table.style.fontSize = document.querySelector("input#fontSize").value;

    for(i = 0; i < document.querySelector("input#cntY").value; i++){
        let el_tr = document.createElement("tr");
        for(j = 0; j < document.querySelector("input#cntX").value; j++){
            let el_td = document.createElement("td");
            el_td.style.maxWidth   = document.querySelector("input#sizeXTd").value;
            el_td.style.maxHeight  = document.querySelector("input#sizeYTd").value;
            
            el_td.style.padding = "0px";
            el_td.style.margin  = "0px";
            
            el_td.style.backgroundColor = "#000000";
            el_td.style.color           = "#FFFFFF";

            el_td.innerHTML = ".";

            el_td.addEventListener("mousemove", editElTd);

            el_tr.append(el_td);
        }
        el_table.append(el_tr);
    }
    

}


function editElTd(e){
    if(e.which == 1){
        e.currentTarget.innerHTML = document.querySelector("input#viewSym").value;
        e.currentTarget.style.color = document.querySelector("input#colorSym").value;
        e.currentTarget.style.backgroundColor = document.querySelector("input#backColorSym").value;
    }
}

