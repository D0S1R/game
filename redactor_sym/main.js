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
let map = "";
let map_color = "";
let arr_map_color = [];


var control = document.getElementById("map_txt_load");
control.addEventListener("change", function(event) {
    // Когда происходит изменение элементов управления, значит появились новые файлы
    var i = 0,
        files = control.files,
        len = files.length;

    let d = 0;
    let a = 0;

    

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
    let map = "";
    let map_color = "";
    let arr_map_color = [{bg:-1,fg:-1}];

    for (; i < len; i++) {
        if(files[i].name.includes("_color") > 1){
            d = i;
        }else{
            a = i;
        }
        console.log("Filename: " + files[i].name);
        console.log("Type: " + files[i].type);
        console.log("Size: " + files[i].size + " bytes");
    }

    var reader_color = new FileReader();
    reader_color.onload = function(event) {
        var contents = event.target.result;
        console.log("Содержимое файла: " + contents.length);
        map_color = contents;

        let str_arr = map_color.split("\n");
        let k = 0;
        for(i = 0; i < str_arr.length; i++){
            let arr_el_el_el = str_arr[i].split(";");
            for(j = 0; j < arr_el_el_el.length; j++){
                let BG_FG = arr_el_el_el[j].split("-");
                arr_map_color[k] = {
                    bg: BG_FG[0],
                    fg: BG_FG[1]
                };
                k++;
            }
        }
    };
    reader_color.onerror = function(event) {
        console.error("Файл не может быть прочитан! код " + event.target.error.code);
    };
    if(i > 1){
        reader_color.readAsText(files[d]);
    }

    var reader = new FileReader();
    reader.onload = function(event) {
        var contents = event.target.result;
        console.log("Содержимое файла: " + contents.length);
        map = contents;

        el_table = document.querySelector("#editColorMap");
        el_table.style.borderSpacing = "0px";
        el_table.style.fontSize = document.querySelector("input#fontSize").value;

        let cntXX = 0;
        for(i = 0; i < contents.length; i++){
            if(contents[i] == "\n"){
                cntXX = i;
                break;
            }
        }
        let cntYY = contents.length / cntXX;
        cntYY -= 1;

        let k = 0;
        let k_color = 0;
        for(i = 0; i < cntYY; i++){
            let el_tr = document.createElement("tr");
            for(j = 0; j < cntXX; j++){
                let el_td = document.createElement("td");
                // el_td.style.maxWidth   = document.querySelector("input#sizeXTd").value;
                // el_td.style.maxHeight  = document.querySelector("input#sizeYTd").value;

                el_td.style.padding = "0px";
                el_td.style.margin  = "0px";
                
                el_td.style.backgroundColor = arr_map_color[0].bg != -1 ? arr_num_col[Number(arr_map_color[k_color].bg)] : "rgb(12, 12, 12)";
                el_td.style.color           = arr_map_color[0].fg != -1 ? arr_num_col[Number(arr_map_color[k_color].fg)] : "rgb(204, 204, 204)";
                k_color++;

                el_td.innerHTML = map[k];
                k++;
                el_td.addEventListener("mouseover", editElTd);
                el_tr.append(el_td);
            }
            k++;
            k_color++;
            // k++;
            el_table.append(el_tr);
        }
    };
    reader.onerror = function(event) {
        console.error("Файл не может быть прочитан! код " + event.target.error.code);
    };
    reader.readAsText(files[a]);

}, false);


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

// редактирование карты
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

