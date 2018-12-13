set clipboard=unnamed


" ==================================================
" Some basic setup i will need to make a script of:

" Permanently swap Esc and Caps on ubuntu
" dconf write /org/gnome/desktop/input-sources/xkb-option \"['caps:swapescape']"

" create folders and clone all the git repos i need for my plugins

" ==================================================

" Map Ctrl-Backspace to delete the previous word in insert mode.



"" Quicksave command


" Bind Ctrl+<movement> keys to move around the windows, instead of using Ctrl+w + <movement>
" Every unnecessary keystroke that can be saved is good for your health :)
map <c-j> <c-w>j
map <c-k> <c-w>k
map <c-l> <c-w>l
map <c-h> <c-w>h


" easier moving between tabs
map <Leader>n <esc>:tabprevious<CR>
map <Leader>m <esc>:tabnext<CR>


" map sort function to a key
vnoremap <Leader>s :sort<CR>


" easier moving of code blocks
" Try to go into visual mode (v), thenselect several lines of code here and
" then press ``>`` several times.
vnoremap < <gv  " better indentation
vnoremap > >gv  " better indentation


" Show whitespace
" MUST be inserted BEFORE the colorscheme command
autocmd ColorScheme * highlight ExtraWhitespace ctermbg=red guibg=red
au InsertLeave * match ExtraWhitespace /\s\+$/


" Uing Source Code Pro
set anti enc=utf-8
set guifont=Source\ Code\ Pro\ 19


" Color scheme
" https://github.com/ErichDonGubler/vim-sublime-monokai
set t_Co=256
color sublimemonokai

" Enable syntax highlighting
" You need to reload this file for the change to apply
filetype off
filetype plugin indent on
syntax on

" Showing line numbers and length
set number  " show line numbers
set tw=79   " width of document (used by gd)
set nowrap  " don't automatically wrap on load
set fo-=t   " don't automatically wrap text when typing
set colorcolumn=80
highlight ColorColumn ctermbg=233
set relativenumber
set so=12

" Easier formatting of paragraphs
vmap Q gq
nmap Q gqap


" Useful settings
set history=700
set undolevels=700


" Real programmers don't use TABs but spaces
set tabstop=4
set softtabstop=4
set shiftwidth=4
set shiftround
set expandtab


" Make search case insensitive
set hlsearch
set incsearch
set ignorecase
set smartcase

" Setup Pathogen to manage your plugins
" mkdir -p ~/.vim/autoload ~/.vim/bundle
" curl -so ~/.vim/autoload/pathogen.vim https://raw.githubusercontent.com/tpope/vim-pathogen/master/autoload/pathogen.vim
" " Now you can install any plugin into a .vim/bundle/plugin-name/ folder
call pathogen#infect()

" ===========================================================================
" Python IDE Setup
" ===========================================================================

" autocmd FileType python inoremap <c-k> <Esc>0i#<Space>

" Fugitive
" cd ~/.vim/bundle
" git clone https://github.com/tpope/vim-fugitive.git
" vim -u NONE -c 'helptags vim-fugitive/doc' -c q
nnoremap <F9> :cprev<CR>
nnoremap <F10> :cnext<CR>

" Settings for vim-airline
" cd ~/.vim/bundle
" git clone https://github.com/vim-airline/vim-airline
set laststatus=2
let g:airline_powerline_fonts = 1

if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif

" unicode symbols
let g:airline_left_sep = '»'
let g:airline_left_sep = '' "'▶'
let g:airline_right_sep = '«'
let g:airline_right_sep = '' "'◀'
let g:airline_symbols.linenr = '␊'
let g:airline_symbols.linenr = '␤'
let g:airline_symbols.linenr = '¶'
let g:airline_symbols.branch = '⎇'
let g:airline_symbols.paste = 'ρ'
let g:airline_symbols.paste = 'Þ'
let g:airline_symbols.paste = '∥'
let g:airline_symbols.whitespace = 'Ξ'
let g:airline_powerline_fonts = 1
let g:airline_theme='minimalist'
" let g:airline_solarized_bg='dark'


" python extra function highlighting
":syntax match pythonFunction /\v[[:alpha:]_.]+\ze(\s?\()/
":hi def link pythonFunction Function


" Settings for ctrlp
" cd ~/.vim/bundle
" git clone https://github.com/ctrlpvim/ctrlp.vim.git
let g:ctrlp_max_height = 30
set wildignore+=*.pyc
set wildignore+=*_build/*
set wildignore+=*/coverage/*


" Settings for jedi-vim
" cd ~/.vim/bundle
" git clone git://github.com/davidhalter/jedi-vim.git
let g:jedi#usages_command = "<leader>z"
let g:jedi#popup_on_dot = 0
let g:jedi#popup_select_first = 0
map <Leader>b Oimport ipdb; ipdb.set_trace() # BREAKPOINT<C-c>


" Better navigating through omnicomplete option list
" See http://stackoverflow.com/questions/2170023/how-to-map-keys-for-popup-menu-in-vim
set completeopt=longest,menuone
function! OmniPopup(action)
    if pumvisible()
        if a:action == 'j'
            return "\<C-N>"
        elseif a:action == 'k'
            return "\<C-P>"
        endif
    endif
    return a:action
endfunction

inoremap <silent><C-j> <C-R>=OmniPopup('j')<CR>
inoremap <silent><C-k> <C-R>=OmniPopup('k')<CR>


" Python folding
" mkdir -p ~/.vim/ftplugin
" wget -O ~/.vim/ftplugin/python_editing.vim http://www.vim.org/scripts/download_script.php?src_id=5492
"set nofoldenable

" NERDtree
" git clone https://github.com/scrooloose/nerdtree.git ~/.vim/bundle/nerdtree
autocmd vimenter * NERDTree
map <C-n> :NERDTreeToggle<CR>
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif

