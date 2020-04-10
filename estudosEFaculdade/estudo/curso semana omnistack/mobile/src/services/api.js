import axios from 'axios';
//url deve ser o ip  mais a porta
const api = axios.create({
    baseURL:'http//'
})

export default api