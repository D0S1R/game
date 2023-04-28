// массив цветов консоли
let arr_num_col = [
    "rgb(12, 12, 12)",
    "rgb(0, 54, 218)",
    "rgb(19, 161, 14)",
    "rgb(58, 150, 221)",
    "rgb(197, 16, 31)",
    "rgb(136, 23, 152)",
    "rgb(193, 156, 0)",
    "rgb(204, 204, 204)",
    "rgb(118, 118, 118)",
    "rgb(59, 120, 255)",
    "rgb(22, 198, 12)",
    "rgb(97, 214, 214)",
    "rgb(231, 72, 86)",
    "rgb(180, 0, 158)",
    "rgb(249, 241, 165)",
    "rgb(242, 242, 242)",
];

let el_table;

// создание "джейсон структуры, с инфой"
// let text = JSON.stringify({hello:'example'});
let map = "";
let map_color = "";
// вызов функции, которая создаст и скачает на комп клиента файл
// downloadAsFile(text);

function madeTxtMap(){
    // el_table;
    map = "";
    el_table = document.querySelector("#editColorMap");
    for(i = 0; i < el_table.children.length; i++){
        let tr_tr = el_table.children[i];
        for(j = 0; j < tr_tr.children.length; j++){
            map = map + tr_tr.children[j].innerHTML;
        }
        map = map + "\n";
    }
}
function madeTxtMapColor(){
    // el_table;
    map_color = "";
    el_table = document.querySelector("#editColorMap");
    for(i = 0; i < el_table.children.length; i++){
        let tr_tr = el_table.children[i];
        for(j = 0; j < tr_tr.children.length; j++){
            // ищем номер цвета
            for(k = 0; k < arr_num_col.length; k++){
                if(tr_tr.children[j].style.backgroundColor == arr_num_col[k]){
                    map_color = map_color + k + "-";
                }
            }
            for(k = 0; k < arr_num_col.length; k++){
                if(tr_tr.children[j].style.color == arr_num_col[k]){
                    map_color = map_color + k + ";";
                }
            }
        }
        map_color = map_color + "\n";
    }
}

let a_map = document.querySelector("a#map_txt");
a_map.onclick = () => {

    madeTxtMap();

    // Создаем файл
    let file_map = new Blob([map], {type: 'application/json'});
    
    // Привязываем к ссылке, или вшиваем в ссылку, объект "файл"
    a_map.href = URL.createObjectURL(file_map);

    // название файла
    a_map.download = document.querySelector("input#nameMap").value + ".txt";
}

let a_map_color = document.querySelector("a#map_color_txt");
a_map_color.onclick = () => {

    madeTxtMapColor();

    // Создаем файл
    let file_map_color  = new Blob([map_color], {type: 'application/json'});
    
    // Привязываем к ссылке, или вшиваем в ссылку, объект "файл"
    a_map_color.href = URL.createObjectURL(file_map_color);

    // название файла
    a_map_color.download = document.querySelector("input#nameMap").value + "_color.txt";
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
    el_table = document.querySelector("#editColorMap");
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
            
            el_td.style.backgroundColor = "rgb(12, 12, 12)";
            el_td.style.color           = "rgb(204, 204, 204)";

            el_td.innerHTML = ".";

            el_td.addEventListener("mouseover", editElTd);

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

