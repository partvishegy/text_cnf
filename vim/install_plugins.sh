
cp .vimrc ~/

mkdir -p ~/.vim/autoload ~/.vim/bundle ~/.vim/colors

curl -LSso ~/.vim/autoload/pathogen.vim https://tpo.pe/pathogen.vim

curl -LSso ~/.vim/colors/sublimemonokai.vim  https://raw.githubusercontent.com/ErichDonGubler/vim-sublime-monokai/master/colors/sublimemonokai.vim

git clone https://github.com/scrooloose/nerdtree.git ~/.vim/bundle/nerdtree

git clone https://github.com/tpope/vim-fugitive.git ~/.vim/bundle/vim-fugitive

git clone --depth=1 https://github.com/vim-syntastic/syntastic.git ~/.vim/bundle/syntastic

git clone https://github.com/xolox/vim-misc ~/.vim/bundle/vim-misc

git clone https://github.com/xolox/vim-easytags ~/.vim/bundle/vim-easytags

apt-get install exuberant-ctags
